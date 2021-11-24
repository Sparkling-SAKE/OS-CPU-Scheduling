#pragma once

#include <iostream>

class Process
{
private:
	int  number_;
	int  arrival_time_;
	int  burst_time_;
	int  waiting_time_;
	int  running_time_;
	bool done_;
	bool running_;

public:
	Process(int number, int arrival_time, int burst_time);
	virtual ~Process() {}

public:
	void PrintStart(int run_time);
	void PrintEnd(int run_time);
	void WaitingTimeUpdate(int run_time);
	bool IsArrival(int run_time) { return run_time >= arrival_time_; }

public:
	void  RunningTimeUpdate();

public:
	int  GetNumber()		const	{ return number_; }
	int  GetArrivalTime()	const	{ return arrival_time_; }
	int  GetBurstTime()		const	{ return burst_time_; }
	int  GetWaitingTime()	const	{ return waiting_time_; }
	int	 GetRunningTime()	const	{ return running_time_; }
	bool GetDone()			const	{ return done_; }
	bool GetRuning()		const	{ return running_; }

	void SetNumber(int number)				{ number_ = number; }
	void SetArrivalTime(int arrival_time)	{ arrival_time_ = arrival_time; }
	void SetBurstTime(int burst_time)		{ burst_time_ = burst_time; }
	void SetWaitingTime(int waiting_time)	{ waiting_time_ = waiting_time; }
	void SetRunningTime(int running_time)	{ running_time_ = running_time; }
	void SetDone(bool done)					{ done_ = done; }
	void SetRunning(bool running)			{ running_ = running; }
};

