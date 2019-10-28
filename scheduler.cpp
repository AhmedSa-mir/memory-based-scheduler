#include "scheduler.h"

void childHandler(int sig)
{
	std::cout << "CHILD SIGNAL" << std::endl;
}

Scheduler::Scheduler(int blocks_cnt) {
	mem_blocks_ = blocks_cnt;
	mem_queues_ = new std::queue<Process*>[mem_blocks_];
	finished_tasks_ = 0;

	// Set handler for SIGCHLD
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = childHandler;
	sigaction(SIGCHLD, &sa, NULL);
}

Scheduler::~Scheduler() {
	delete mem_queues_;
}

void Scheduler::finishProcess(int pid)
{
	finished_tasks_++;
	
	// remove the process from queue
	std::queue<Process*>* q = &mem_queues_[processes[pid]->mem_block_];
	Process* p = q->front();
	q->pop();
	delete p;

	// schedule the next process
	if(!q->empty()){
		runProcess(q->front());
	}
}

void Scheduler::queueProcess(Process* p)
{
	// run process if queue was empty
	if (mem_queues_[p->mem_block_].empty()) {
		runProcess(p);
	}

	mem_queues_[p->mem_block_].push(p);
}

void Scheduler::runProcess(Process* p)
{
	int id = fork();
	if (id == 0) {	// child process
		execl("process.out", std::to_string(p->mem_block_).c_str(),
		 					 std::to_string(p->time_).c_str(),
		 					 (char *)NULL);
	}

	processes[id] = p;
}

bool Scheduler::finished()
{
	return finished_tasks_ == processes.size();
}