#include "TrainStation.h"

void TrainStation::showOne(const string& nameOrTime) {
	for (auto& train : trains) {
		if (train.getName() == nameOrTime) {
			showOne(train);
			return;
		}
		if (train.getTime() == nameOrTime) {
			showOne(train);
			return;
		}
	}

	cout << "Not found!" << endl;
}

void TrainStation::showOne(int num) {
	for (auto& train : trains) {
		if (train.getNum() == num)
			showOne(train);
		return;
	}

	cout << "Not found!" << endl;
}

void TrainStation::showOne(Train& train) {
	cout << "Train N-" << train.getNum() << endl <<
		"Name - " << train.getName() << endl <<
		"Time - " << train.getTime() << endl << endl;
}