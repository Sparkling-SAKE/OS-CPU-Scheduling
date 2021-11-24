#pragma once
#include "Process.h"
#include <list>

class RR
{
private:
	int run_time_;
	const int kTimeQuentum_ = 3;

public:
	RR();
	virtual ~RR();

public:
	void Run(std::list<Process> process_list);
	float AverageWaitingTime(const std::list<Process>& process_list)	const;
};

