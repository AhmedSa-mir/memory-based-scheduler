#include <iostream>
#include <chrono>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
#include "utils.h"

int main()
{
	// init seed
	srand((unsigned)time(0));
	
	const int PROCESSES_CNT = 20;			// #Tasks created
	const int MEM_BLOCKS = 1000;			// number of blocks(chunks)
	const int EXEC_TIME_MAX = 10;			// max execution time in seconds
	const int EXEC_TIME_MIN = 2;			// min execution time in seconds

	// fork scheduler process
	int pid = fork();
	if (pid == 0) {	// child process 
		execl("sched_process", std::to_string(MEM_BLOCKS).c_str(), (char *)NULL);
	}

	// wait for ready message from scheduler
	key_t qid = msgget(getpid(), 0666 | IPC_CREAT);
	int_msg recv_msg;
    msgrcv(qid, &recv_msg, sizeof(recv_msg.msg), 1, !IPC_NOWAIT);

	// create processes
	for (int i = 0; i < PROCESSES_CNT; i++) {
		
		// obtain process parameters
		int mem_block = rand() % MEM_BLOCKS;
		int exec_time = (rand() % EXEC_TIME_MAX) + EXEC_TIME_MIN;

		Process p(exec_time, mem_block);

		proc_msg send_msg;
			
		// send message with the process info to the scheduler
		if(i < PROCESSES_CNT - 1){
	    	send_msg.msg_type = 1;
		}
		else {
			send_msg.msg_type = 2;		// end process
		}
	    send_msg.p = p;
	    msgsnd(qid, &send_msg, sizeof(send_msg.p), !IPC_NOWAIT);

		std::cout << i+1 << " process(es) generated\n";
	}

	int status;
	pid = wait(&status);

	if(pid == -1) {
		std::cout << "ERROR: Scheduler returned -1" << std::endl;
	}
	else if (WIFEXITED(status)) {
		std::cout << "Scheduler exited successfully!" << std::endl;
	}
	else if (WIFSIGNALED(status)) {
		std::cout << "Scheduler signalled with status " << WTERMSIG(status) << std::endl;
	}

	return 0;
}
