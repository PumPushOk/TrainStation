#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Train.h"
using namespace std;

class TrainStation
{
public:
	void showOne(const string& nameOrTime);
	void showOne(int num);
	void showOne(Train& train);

	void showAll() {
		for (auto& train : trains)
			showOne(train);
	}

	void addTrain() {
		Train tn;

		tn.setName();
		tn.setNumber();
		tn.setTime();

		trains.push_back(tn);
	}

private:

	vector<Train> trains;
};

