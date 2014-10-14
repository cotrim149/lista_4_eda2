//============================================================================
// Name        : algoritmo_guloso_interval_scheduling.cpp
// Author      : Cotrim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include "Job.h"

using namespace std;

int main() {

	int qtdCriterios = 6;

	vector<int> criterios;

	for(int i=0;i< qtdCriterios;i++){
		int valor=1;
		criterios.push_back(valor);
	}

	int higherNumbers[qtdCriterios];

	Job jobs;

	vector<Job> jobsStartTime;
	vector<Job> jobsEndTime;
	vector<Job> jobsLenght;
	vector<int> jobStartTimeCompability;
	vector<int> jobEndTimeCompatibility;
	vector<int> jobSizeLenghtCompatibility;

	string criterio1 = "\nJobs sorted by Start time with algorithm start time\n";
	string criterio2 = "\nJobs sorted by Start Time with algorithm end time\n";
	string criterio3 = "\nJobs sorted by end time with algorithm end time\n";
	string criterio4 = "\nJobs sorted by end Time with algorithm start time\n";
	string criterio5 = "\nJobs sorted by interval length with algorithm start time\n";
	string criterio6 = "\nJobs sorted by interval length with algorithm end time\n";
	bool saida=false;

	while(!saida){
		for(int i=0;i<qtdCriterios;i++){
			jobs.createRandomTasks(10);
			jobs.printJobs();

			switch(i){
				case 0:

					if(criterios.at(i)==1){
						jobs.sortJobsStartTime();
						cout << criterio1 << endl;
						jobsStartTime = jobs.jobs;
						jobStartTimeCompability = jobs.verifyCompatibilityStartTime(jobsStartTime,true);
						higherNumbers[i] = jobs.verifyMajor(jobStartTimeCompability);

					}else{
						higherNumbers[i]=-1;
					}

				break;
				case 1:
					if(criterios.at(i)==1){
						jobs.sortJobsStartTime();
						jobsStartTime = jobs.jobs;
						cout << criterio2 << endl;
						jobEndTimeCompatibility = jobs.verifyCompatibilityEndTime(jobsStartTime,true);
						higherNumbers[i] = jobs.verifyMajor(jobEndTimeCompatibility);

					}else{
						higherNumbers[i]=-1;
					}
				break;
				case 2:
					if(criterios.at(i)==1){
						jobs.sortJobsEndTime();
						jobsEndTime = jobs.jobs;
						cout << criterio3 << endl;
						jobStartTimeCompability = jobs.verifyCompatibilityEndTime(jobsEndTime,true);
						higherNumbers[i] = jobs.verifyMajor(jobStartTimeCompability);

					}else{
						higherNumbers[i]=-1;
					}

				break;
				case 3:
					if(criterios.at(i)==1){
						jobs.sortJobsEndTime();
						jobsEndTime = jobs.jobs;
						cout << criterio4 << endl;
						jobEndTimeCompatibility = jobs.verifyCompatibilityStartTime(jobsEndTime,true);
						higherNumbers[i] = jobs.verifyMajor(jobEndTimeCompatibility);
					}else{
						higherNumbers[i]=-1;
					}

				break;
				case 4:
					if(criterios.at(i)==1){
						jobs.sortJobsIntervalLength();
						jobsLenght = jobs.jobs;
						cout << criterio5 << endl;
						jobSizeLenghtCompatibility = jobs.verifyCompatibilityStartTime(jobsLenght,true);
						higherNumbers[i] = jobs.verifyMajor(jobSizeLenghtCompatibility);

					}else{
						higherNumbers[i]=-1;
					}
				break;
				case 5:
					if(criterios.at(i) == 1){
						jobs.sortJobsIntervalLength();
						jobsLenght = jobs.jobs;
						cout << criterio6 << endl;
						jobSizeLenghtCompatibility=jobs.verifyCompatibilityEndTime(jobsLenght,true);
						higherNumbers[i] = jobs.verifyMajor(jobSizeLenghtCompatibility);

					}else{
						higherNumbers[i]=-1;
					}
				break;
			}
		}

		int count=0;
		int minorID = jobs.verifyMinor(higherNumbers,qtdCriterios);
		criterios.at(minorID) = 0;

		for(int i=0;i<qtdCriterios;i++){
			if(criterios.at(i)==1)
				count++;
		}

		if(count == 1){
			saida=true;
		}

	}
	int id;
	for(int i=0;i<qtdCriterios;i++){
		if(criterios.at(i)==1)
			id = i;
	}


	cout << "Critérios usados " << endl;

	cout << "0 - " << criterio1 << endl;
	cout << "1 - " << criterio2 << endl;
	cout << "2 - " << criterio3 << endl;
	cout << "3 - " << criterio4 << endl;
	cout << "4 - " << criterio5 << endl;
	cout << "5 - " << criterio6 << endl;


	cout << "ID critério: " << id << endl;


	/*
	 * Verifica menor no vetor e seta zero no vetor de critérios
	 * restando somente 1 critério parar loop
	 */

	return 0;
}
