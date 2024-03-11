#pragma once
#include "LeaveTime.h"
#include <iostream>
#include <string>
using namespace std;

#define MAX_NAME_SIZE 30
#define MIN_NAME_SIZE 3

struct Train {
	void setName();
	void setNumber();
	void setTime();

	const string& getName() const {
		return name;
	}

	int getNum() const {
		return number;
	}

	const string getTime() const {
		 return time.timeStr();
	}

private:
	string name = "";
	int number = 0;
	LeaveTime time;
};