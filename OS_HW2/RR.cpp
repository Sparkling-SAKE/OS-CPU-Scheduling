#include "RR.h"

RR::RR()	:
	run_time_(0)
{
}

RR::~RR()
{
}

void RR::Run(std::list<Process> process_list)
{
	std::cout << "=================== RR Scheduling Start ===================" << std::endl;

	auto running_process = process_list.begin();
	auto prior_running_process = running_process;
	running_process->PrintStart(run_time_);
	running_process->SetRunning(true);

	bool flag = true;
	int process_run_time = 0;
	while (flag)
	{
		flag = false;
		if (prior_running_process != running_process && !running_process->GetDone())
		{
			prior_running_process->SetRunning(false);
			prior_running_process->PrintEnd(run_time_);
			running_process->SetRunning(true);
			running_process->PrintStart(run_time_);
			prior_running_process = running_process;
		}

		process_run_time++;
		run_time_++;

		if (run_time_ == 153)
			int a = 1;

		running_process->RunningTimeUpdate();

		for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
			iter->WaitingTimeUpdate(run_time_);

		if (running_process->GetDone() || process_run_time == kTimeQuentum_)
		{
			running_process++;
			for (; running_process != process_list.end(); ++running_process)
				if (!running_process->GetDone())
					break;

			process_run_time = 0;
			if (running_process == process_list.end())
				running_process = process_list.begin();
			if (running_process->GetArrivalTime() > run_time_)
				running_process = process_list.begin();
		}

		for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
			if (!iter->GetDone())
				flag = true;

	}
	running_process->PrintEnd(run_time_);

	std::cout << "Waiting time for ";
	for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
	{
		std::cout << "P" << iter->GetNumber() << " = " << iter->GetWaitingTime() << "; ";
	}
	std::cout << std::endl;
	std::cout << "Average Waiting time : " << AverageWaitingTime(process_list) << std::endl;;
	std::cout << "=================== RR Scheduling End ===================" << std::endl << std::endl;
}

float RR::AverageWaitingTime(const std::list<Process>& process_list) const
{
	float waiting_time_sum = 0.f;
	for (auto iter = process_list.begin(); iter != process_list.end(); ++iter)
		waiting_time_sum += iter->GetWaitingTime();

	return waiting_time_sum / process_list.size();
}
