#include <iostream>
#include <queue>
#include <map>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <cstring>
#include "utils.h"

typedef unsigned char byte;

class Scheduler {
private:
	int mem_blocks_;						// number of memory blocks(chunks)
	std::queue<Process*>* mem_queues_;		// queue of processes for each memory block
	std::map<int, Process*> processes;		// map <process_id, process>
	int finished_tasks_;					// count of the finished tasks
public:
	Scheduler(int blocks_cnt);
	~Scheduler();
	void queueProcess(Process* p);
	void finishProcess(int pid);
	void runProcess(Process* p);
	int getFinishedTasks();
	bool finished();
};