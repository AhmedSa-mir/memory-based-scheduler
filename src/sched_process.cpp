#include <iostream>
#include <unistd.h>
#include <string>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <chrono>
#include "scheduler.h"

int main(int argc, char* argv[]) {

	const int MEM_BLOCKS = std::stoi(argv[0]);		// number of memory blocks(chunks)
	
	int pid = getpid();

	Scheduler sched(MEM_BLOCKS);

	// 2 message queues one with the process generator and the other with child processes
	key_t qid = msgget(getppid(), IPC_CREAT);
	key_t q2id = msgget(pid, 0666 | IPC_CREAT);

	// Send message with the process id to the scheduler
	int_msg message;
	message.msg_type = 1;
	message.msg = pid;		// anything
	msgsnd(qid, &message, sizeof(message.msg), !IPC_NOWAIT);

	bool end = false;

	while(!end) {
		
		// receive message with the process info
		proc_msg recv_msg;
		ssize_t ret = msgrcv(qid, &recv_msg, sizeof(recv_msg.p), 0, !IPC_NOWAIT);

		if(ret == -1) {
			std::cout << std::strerror(errno) << std::endl;
		}
		else {
			if(recv_msg.msg_type == 2) {	// end message
				end = true;
			}
			Process* p = new Process(recv_msg.p.time_, recv_msg.p.mem_block_);
			sched.queueProcess(p);
		}

	}

	while (!sched.finished()) {

		int status;
		int cid = wait(&status);	// wait for a child exit

		if(cid == -1) {
			std::cout << "ERROR: Child returned -1" << std::endl;
		}
		else if (WIFEXITED(status)) {
			std::cout << "Child " << cid << " exited successfully!" << std::endl;
		}
		else {
			std::cout << "Child " << cid << " signalled with status " << status << std::endl;
		}

		ssize_t ret = 0;

		while (ret != -1) {

			// get children messages
			int_msg recv_msg;
			ret = msgrcv(q2id, &recv_msg, sizeof(recv_msg.msg), 1, IPC_NOWAIT);

			if(ret != -1) {
				sched.finishProcess(recv_msg.msg);
			}
		}
	}

	exit(0);
}