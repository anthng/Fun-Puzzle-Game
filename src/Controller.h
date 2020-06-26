#pragma once
#include "utils.h"

void Controller(vector<Questions> vQuestions) {

	string  name; int score;
	cout << "\n\n\t\t         *********************";
	cout << "\n\n\t\t         *  Fun Puzzle Game  *";
	cout << "\n\n\t\t         *********************";
	cout << "\n\n\t\tEnter your name: ";
	getline(cin, name);

	system(CLRSCR_CMD);

	while (1) {
		menu(name);

		int sel;
		cout << "\t\t";
		cin >> sel;
		cin.ignore();

		switch (sel) {

		case 1: {

			while (1) {
				score = 0;
				Player p(name, score);
				string choice;
				system(CLRSCR_CMD);

				int n = vQuestions.size();
				int i = 0;

				while (i < n) {
					//string choice;
					cout << "\n\t\t\t" << name << "\t\tScore: " << score << endl;

					cout << "\n\t" << i + 1 << ")\t";
					vQuestions[i].display();
					getline(cin, choice);
					choice = strtoupper(choice);
					if (vQuestions[i].checkAnswer(choice)) {
						cout << "\n\t\t\tCONGRATULATIONS!!!!";
						score++;
					}
					else {
						cout << "\n\t\t\t\tPoor you!!!!!" << endl;
						cout << "\t\t\t\tTrue Answer:  " << vQuestions[i].getTrueAns();
					}

					//delay 2 seconds
					cout << "\n\t\t\t\t";
					Sleep(2);
					i += 1;
					system(CLRSCR_CMD);
				}

				//achievement
				ofstream fScores;
				p.addScores(score);
				p.recordScores(fScores);

				cout << "\n\t\t\t" << name << " gain " << score << " scores\n";
				cout << "\t\tPress 1 to continue or any key to exit game.\n\t\t";

				string ch;
				cin >> ch;
				cin.ignore();

				if (ch.compare("1")) {
					break;
				}

				vQuestions = Shuffle(vQuestions);
			}
			break;
		}




		case 2: {
			system(CLRSCR_CMD);
			leaderBoard();
			string ch;
			getline(cin, ch);
			break;
		}



		case 3: {
			system(CLRSCR_CMD);
			About();
			string ch;
			getline(cin, ch);
			break;
		}


		default:
			exit(0);
		}

	}
}
