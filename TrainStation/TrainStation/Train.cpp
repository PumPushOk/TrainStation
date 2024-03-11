#include "Train.h"

void Train::setName() {
	cout << "Enter name -> ";
	getline(cin, name);

	if (name.size() > MAX_NAME_SIZE) {
		cout << "No more than " << MAX_NAME_SIZE << " symbols!" << endl;
		setName();
	}
	if (name.size() < MIN_NAME_SIZE) {
		cout << "No less than " << MIN_NAME_SIZE << " symbols!" << endl;
		setName();
	}
	if (name.find(' ') != string::npos) {
		cout << "There should no be spaces!" << endl;
		setName();
	}
}

void Train::setNumber() {
	cout << "Enter number -> ";
	cin >> number;
	cin.ignore();

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Enter a number!" << endl;
		setNumber();
	}
}

void Train::setTime() {
	while (true) {
		cout << "Enter hour of leaving -> ";
		cin >> time.hour;
		cin.ignore();

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter a number!" << endl;
			continue;
		}

		if (time.hour > 23 || time.hour < 0) {
			cout << "Enter number from 0 till 23!" << endl;
			continue;
		}

		break;
	}

	while (true) {
		cout << "Enter minute of leaving -> ";
		cin >> time.minute;
		cin.ignore();

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter a number!" << endl;
			continue;
		}

		if (time.minute > 59 || time.minute < 0) {
			cout << "Enter number from 0 till 59!" << endl;
			continue;
		}

		break;
	}
}