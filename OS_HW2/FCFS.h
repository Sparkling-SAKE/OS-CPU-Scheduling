#pragma once
#include "Process.h"
#include <list>

class FCFS
{
private:
	int run_time_;

public:
	FCFS();
	virtual ~FCFS();

public:
	void Run(std::list<Process> process_list);
	float AverageWaitingTime(const std::list<Process>& process_list)	const;
};
