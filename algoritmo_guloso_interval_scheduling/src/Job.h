/*
 * Job.h
 *
 *  Created on: Oct 6, 2014
 *      Author: cotrim
 */

#ifndef JOB_H_
#define JOB_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <climits>

using namespace std;

class Job {
public:
	Job();
	virtual ~Job();

    int id;
    float startTime;
	float endTime;
	float intervalLength;
	vector<Job> jobs;

	float getEndTime() const;
    float getStartTime() const;
    void setEndTime(float endTime);
    void setStartTime(float startTime);
    vector<Job> createRandomTasks(int totalTasks);
    void printJobs();
    void sortJobsStartTime();
    void sortJobsEndTime();
    void sortJobsIntervalLength();
    vector<int> verifyCompatibilityStartTime(vector<Job> jobs, bool compatibility);
    vector<int> verifyCompatibilityEndTime(vector<Job> jobs,bool compatibility);
    int verifyMajor(vector<int> numbers);
    int verifyMinor(int *numbers,int qtd);
};

#endif /* JOB_H_ */
