#include "FCFS.h"

FCFS::FCFS()	:
	run_time_(0)
{
}

FCFS::~FCFS()
{
}

void FCFS::Run(std::list<Process> process_list)
{
	std::cout << "=================== FCFS Scheduling Start ===================" << std::endl;

	auto running_process = process_list.begin();
	running_process->PrintStart(run_time_);
	running_process->SetRunning(true);
	while (true)
	{
		run_time_++;

		running_process->RunningTimeUpdate();

		for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
			iter->WaitingTimeUpdate(run_time_);

		if (running_process->GetDone())
		{
			running_process->SetRunning(false);
			running_process->PrintEnd(run_time_);
			running_process++;

			if (running_process == process_list.end())
				break;

			running_process->SetRunning(true);
			running_process->PrintStart(run_time_);
		}
	}

	std::cout << "Waiting time for ";
	for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
	{
		std::cout << "P" << iter->GetNumber() << " = " << iter->GetWaitingTime() << "; ";
	}
	std::cout << std::endl;
	std::cout << "Average Waiting time : " << AverageWaitingTime(process_list) << std::endl;;
	std::cout << "=================== FCFS Scheduling End ===================" << std::endl << std::endl;
}	


float FCFS::AverageWaitingTime(const std::list<Process>& process_list) const
{
	float waiting_time_sum = 0.f;
	for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
		waiting_time_sum += iter->GetWaitingTime();

	return waiting_time_sum / process_list.size();
}
