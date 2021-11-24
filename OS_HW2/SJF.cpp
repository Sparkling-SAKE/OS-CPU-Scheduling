#include "SJF.h"

SJF::SJF()	:
	run_time_(0)
{
}

SJF::~SJF()
{
}

void SJF::Run(std::list<Process> process_list)
{
	std::cout << "=================== Preemptive SJF Scheduling Start ===================" << std::endl;
	

	auto running_process = process_list.begin();
	int min = INT_MAX;
	for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
	{
		if (iter->IsArrival(run_time_) && !iter->GetDone() && (iter->GetBurstTime() - iter->GetRunningTime()) < min)
		{
			running_process = iter;
			min = running_process->GetBurstTime() - running_process->GetRunningTime();
		}
	}

	auto prior_running_process = running_process;
	running_process->PrintStart(run_time_);
	running_process->SetRunning(true);

	bool loop_flag = true;
	bool compare_flag = false;
	while (loop_flag)
	{
		loop_flag = false;

		if (prior_running_process != running_process && !running_process->GetDone())
		{
			prior_running_process->SetRunning(false);
			prior_running_process->PrintEnd(run_time_);
			running_process->SetRunning(true);
			running_process->PrintStart(run_time_);
			prior_running_process = running_process;
		}

		run_time_++;
		running_process->RunningTimeUpdate();

		for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
		{
			iter->WaitingTimeUpdate(run_time_);
			if (iter->GetArrivalTime() == run_time_)
				compare_flag = true;
		}

		if (running_process->GetDone())
			compare_flag = true;

		if (compare_flag)
		{
			min = INT_MAX;
			auto min_process = process_list.begin();

			for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
			{
				if (iter->IsArrival(run_time_) && !iter->GetDone() && (iter->GetBurstTime() - iter->GetRunningTime()) < min)
				{
					min_process = iter;
					min = min_process->GetBurstTime() - min_process->GetRunningTime();
				}
			}
			running_process = min_process;
			compare_flag = false;
		}


		for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
			if (!iter->GetDone())
				loop_flag = true;
	}
	running_process->PrintEnd(run_time_);

	std::cout << "Waiting time for ";
	for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
	{
		std::cout << "P" << iter->GetNumber() << " = " << iter->GetWaitingTime() << "; ";
	}
	std::cout << std::endl;
	std::cout << "Average Waiting time : " << AverageWaitingTime(process_list) << std::endl;;
	std::cout << "=================== Preemptive SJF Scheduling End ===================" << std::endl << std::endl;
}

float SJF::AverageWaitingTime(const std::list<Process>& process_list) const
{
	float waiting_time_sum = 0.f;
	for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
		waiting_time_sum += iter->GetWaitingTime();

	return waiting_time_sum / process_list.size();
}
