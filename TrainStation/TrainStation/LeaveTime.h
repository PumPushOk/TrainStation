#pragma once
#include <string>
using namespace std;

struct LeaveTime {
	const string timeStr() const {
		string time;

		time.append(to_string(hour));

		time.push_back(':');

		if (minute < 10)
			time.push_back('0');
		time.append(to_string(minute));

		return time;
	}

	int hour = 0;
	int minute = 0;
};