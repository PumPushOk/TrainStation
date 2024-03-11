#pragma once
#include <Windows.h>
#include <conio.h>
#include "TrainStation.h"

#define RETREAT_LENGTH 3
#define ACTIONS_COUNT 4

enum Arrows { Arrow = 224, Up = 72, Down = 80, Enter = 13 };
enum Choice { Add, Show, All, Exit };

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class App {
public:
	void run() {
		//ћ≥н€ю назву в≥кна
		SetConsoleTitleA("TrainStation");

		offCursor();

		cout << "Welcome in TrainStation!" << endl;
		_getch();
		system("cls");

		while (true) {
			int choice = menu();

			system("cls");

			switch (choice) {
			case Add:
				station.addTrain();
				break;
			case Show:
			{
				cout << "Enter name or time of leaving -> ";
				string str;
				getline(cin, str);

				station.showOne(str);
				break;
			}
			case All:
				station.showAll();
				break;
			case Exit:
				return;
			}

			_getch();
			system("cls");
		}
	}

private:
	TrainStation station;

	short menu() {
		short curPos = 0;

		showOptions();

		SetConsoleCursorPosition(hConsole, { 0, curPos });
		cout << "-->";

		while (true) {
			if (_kbhit()) {
				unsigned char ch = _getch();
				if (ch == Arrow) {
					ch = _getch();

					if (ch == Up) {
						SetConsoleCursorPosition(hConsole, { 0, curPos });
						for (int i = 0; i < RETREAT_LENGTH; i++)
							cout << ' ';

						if (curPos == 0)
							curPos = ACTIONS_COUNT - 1;
						else
							curPos--;
					}
					else if (ch == Down) {
						SetConsoleCursorPosition(hConsole, { 0, curPos });
						for (int i = 0; i < RETREAT_LENGTH; i++)
							cout << ' ';

						if (curPos == ACTIONS_COUNT - 1)
							curPos = 0;
						else
							curPos++;
					}


					SetConsoleCursorPosition(hConsole, { 0, curPos });
					cout << "-->";
				}
				else if (ch == Enter)
					return curPos;
			}
		}
	}

	void showOptions() {
		string retreat;
		for (int i = 0; i < RETREAT_LENGTH; i++)
			retreat.push_back(' ');

		cout << retreat << "Add" << endl;
		cout << retreat << "Show" << endl;
		cout << retreat << "All" << endl;
		cout << retreat << "Exit" << endl;
	}

	void offCursor() {
		CONSOLE_CURSOR_INFO cursorInfo;
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(hConsole, &cursorInfo);
	}
};