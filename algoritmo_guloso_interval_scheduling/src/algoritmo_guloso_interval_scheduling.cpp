//============================================================================
// Name        : algoritmo_guloso_interval_scheduling.cpp
// Author      : Cotrim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include "Job.h"

using namespace std;

int main() {


	Job jobs;

	jobs.createRandomTasks();
	jobs.printJobs();

	jobs.sortJobsStartTime();
	cout << "\nJobs sorted Start time\n" << endl;
	jobs.printJobs();
	vector<Job> jobsStartTime = jobs.jobs;
	vector<int> jobStartTimeCompability = jobs.verifyCompatibilityStartTime(jobsStartTime);


	jobs.sortJobsEndTime();
	cout << "\nJobs sorted end time\n" << endl;
	jobs.printJobs();
	vector<Job> jobsEndTime = jobs.jobs;
	jobs.verifyCompatibilityEndTime(jobsEndTime);

//	jobs.sortJobsIntervalLength();
//	cout << "\nJobs sorted interval length\n" << endl;
//	jobs.printJobs();

//	ordenar por horário

	return 0;
}
