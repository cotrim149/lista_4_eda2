//============================================================================
// Name        : algoritmo_guloso_interval_scheduling.cpp
// Author      : Cotrim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
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

	jobs.verifyCompatibilityStartTime(jobsStartTime);


//	jobs.sortJobsEndTime();
//	cout << "\nJobs sorted end time\n" << endl;
//	jobs.printJobs();
//
//	jobs.sortJobsIntervalLength();
//	cout << "\nJobs sorted interval length\n" << endl;
//	jobs.printJobs();

//	ordenar por horário

	return 0;
}
