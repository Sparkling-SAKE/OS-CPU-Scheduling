#pragma once
#include "Process.h"
#include <list>

class SJF
{
private:
	int run_time_;

public:
	SJF();
	virtual ~SJF();

public:
	void Run(std::list<Process> process_list);
	float AverageWaitingTime(const std::list<Process>& process_list)	const;
};

