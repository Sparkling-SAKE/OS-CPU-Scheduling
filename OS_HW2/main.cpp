
#include <iostream>
#include <fstream>
#include <list>
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "RR.h"

using namespace std;

void GetProcessInfo(ifstream& fin, list<Process>& process_list);

int main()
{
	ifstream fin("input.txt");
	list<Process> process_list;


	GetProcessInfo(fin, process_list);

	FCFS run_FCFS;
	run_FCFS.Run(process_list);

	SJF run_SJF;
	run_SJF.Run(process_list);

	RR  run_RR;
	run_RR.Run(process_list);

	return 0;
}

void GetProcessInfo(ifstream& fin, list<Process>& process_list)
{
	int process_number;		fin >> process_number;
	int arrival_time;
	int burst_time;
	for (int i = 0; i < process_number; ++i)
	{
		fin >> arrival_time;
		fin >> burst_time;
		process_list.push_back(std::move(Process(i + 1, arrival_time, burst_time)));
	}

}
