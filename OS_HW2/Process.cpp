#include "Process.h"

Process::Process(int number, int arrival_time, int burst_time)	:
	number_(number),
	arrival_time_(arrival_time),
	burst_time_(burst_time),
	waiting_time_(0),
	running_time_(0),
	done_(false),
	running_(false)
{
}

void Process::PrintStart(int run_time)
{
	std::cout << "P" << number_ << " : " << run_time;
}

void Process::PrintEnd(int run_time)
{
	std::cout << " ~ " << run_time << std::endl;
}

void Process::WaitingTimeUpdate(int run_time)
{
	if (run_time > arrival_time_ && !done_ && !running_)
		waiting_time_++;
}

void Process::RunningTimeUpdate()
{
	if (!done_)
	{
		running_time_++;
		if (running_time_ == burst_time_)
			done_ = true;
	}
}
