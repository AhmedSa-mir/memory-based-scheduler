
// process data
struct Process {
	int time_;
	int mem_block_;
	Process(){time_ = 0; mem_block_ = 0;}
	Process(int time, int mem_block): time_(time), mem_block_(mem_block) {}
};

// message structs for message queues
struct int_msg { 
    long msg_type; 
    int msg; 
};

struct proc_msg { 
    long msg_type;
    Process p; 
};