/*
 * Job.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: cotrim
 */

#include "Job.h"

Job::Job() {
	// TODO Auto-generated constructor stub

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

float Job::getEndTime() const
{
    return endTime;
}

float Job::getStartTime() const
{
    return startTime;
}

void Job::setEndTime(float endTime)
{
    this->endTime = endTime;
}

void Job::setStartTime(float startTime)
{
    this->startTime = startTime;
}


void roundNumber(float *value){

	int absolutValue = *value;
	float rest = *value - absolutValue;

	if(rest > 0.6){
		*value = absolutValue + 1;
	}else if(rest < 0.4){
		*value = absolutValue;
	} else{
		*value = absolutValue + 0.5;
	}

}

vector<Job> Job::createRandomTasks(){

	srand (static_cast <unsigned> (time(0)));

	int totalTasks = 10;


	for(int i=0;i<totalTasks;i++){

		float startTime = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10)) + 8;
		float endTime = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/9)) + 9;

		while(endTime < startTime){
			if(startTime > 17.5){
				startTime = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10)) + 8;
			}

			endTime = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/9)) + 9;

		}

		roundNumber(&startTime);
		roundNumber(&endTime);


		Job job;
		job.setStartTime(startTime);
		job.setEndTime(endTime);
		job.intervalLength = job.getEndTime() - job.getStartTime();

		this->jobs.push_back(job);

	}



	return this->jobs;
}

void Job::printJobs(){


	for(unsigned int i=0; i< this->jobs.size(); i++){
		cout << "Tarefa: " << i << endl;
		cout << "Start Time: " << this->jobs[i].getStartTime() << endl;
		cout << "End Time: " << this->jobs[i].getEndTime() << endl;
		cout << "Interval length: " << this->jobs[i].intervalLength << endl;
	}

}

void Job::sortJobsStartTime(){


	for(unsigned int j=0; j< this->jobs.size();j++){
		for(unsigned int i=0; i< this->jobs.size() - 1;i++){

			if(this->jobs[i].getStartTime() > this->jobs[i+1].getStartTime()){
				Job tempJob = this->jobs[i+1];

				this->jobs[i+1] = this->jobs[i];
				this->jobs[i] = tempJob;

			}

		}

	}
}

void Job::sortJobsEndTime(){


	for(unsigned int j=0; j< this->jobs.size();j++){
		for(unsigned int i=0; i< this->jobs.size() - 1;i++){

			if(this->jobs[i].getEndTime() > this->jobs[i+1].getEndTime()){
				Job tempJob = this->jobs[i+1];

				this->jobs[i+1] = this->jobs[i];
				this->jobs[i] = tempJob;

			}

		}

	}

}

void Job::sortJobsIntervalLength(){


	for(unsigned int j=0; j< this->jobs.size();j++){
		for(unsigned int i=0; i< this->jobs.size() - 1;i++){

			if(this->jobs[i].intervalLength > this->jobs[i+1].intervalLength){
				Job tempJob = this->jobs[i+1];

				this->jobs[i+1] = this->jobs[i];
				this->jobs[i] = tempJob;

			}

		}

	}

}




