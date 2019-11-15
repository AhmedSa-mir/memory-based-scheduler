#include <iostream>
#include <unistd.h>
#include <string>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include "utils.h"

int main(int argc, char* argv[]) {

	int mem_block = std::stoi(argv[0]);
	int exec_time = std::stoi(argv[1]);
	int pid = getpid();

	std::cout << "Process " << pid << " started\n";

	// Process simulation
	usleep(exec_time * 1000000);

	// Send message with the process id to the scheduler
	key_t qid = msgget(getppid(), IPC_CREAT);
	int_msg message;
    message.msg_type = 1;
    message.msg = pid;		// anything
    msgsnd(qid, &message, sizeof(message.msg), !IPC_NOWAIT);

	std::cout << "Process " << pid << " finished\n";
	exit(0);
}