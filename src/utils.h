#ifndef UTILS
#define UTILS

/*
 * This file contains the functions to process extra features:
 * GUI, loading data, the player's score, etc
 */

#ifdef _WIN32
#include <windows.h>
#define Sleep(t) Sleep(t * 1e3);

#define CLRSCR_CMD "cls"
#elif __linux__
#include <unistd.h>
#define Sleep(t) usleep(t * 1e6);
#define CLRSCR_CMD "clear"
#endif

#include <vector>
#include <time.h>
#include "Questions.h"
#include "Player.h"

void swap(Questions &q1, Questions &q2) {
	Questions tmp = q1;
	q1 = q2;
	q2 = tmp;
}

void swap(Player &p1, Player &p2) {
	Player tmp = p1;
	p1 = p2;
	p2 = tmp;
}

string strtoupper(string str) {
	int length = str.length();
	for (int i = 0; i < length; i++) {
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	}
	return str;
}

vector<Questions> Shuffle(vector<Questions> q) {
	srand(time(NULL));
	int n = q.size();
	for (int i = n - 1; i >= 0; i--) {
		int j = (rand() % (i + 1));
		swap(q[i], q[j]);
	}
	return q;
}


vector<Questions> readFile(ifstream& _f) {

	/*
	 * Argument: _f -- The text file containing your data
	 *
	 * Return: vQuestions -- return an unordered Questions vector
	 */

	vector<Questions> vQuestions;

	if (_f.is_open()) {
		string n;
		//the first line containing n-questions;
		getline(_f, n);

		while (!_f.eof()) {
			string qu, ty;
			string ans1, ans2, ans3, ans4;
			string true_ans;

			//get question type
			getline(_f, ty);

			//get question
			getline(_f, qu);

			if (!ty.compare("M")) {

				//get answers
				getline(_f, ans1);
				getline(_f, ans2);
				getline(_f, ans3);
				getline(_f, ans4);

				//get true answer
				getline(_f, true_ans);

				Questions q = Questions(qu, ty, ans1, ans2, ans3, ans4, true_ans);

				//push into vector
				vQuestions.push_back(q);
				continue;
			}

			if (ty.compare("M")) {
				getline(_f, true_ans);
				Questions q = Questions(qu, ty, true_ans);
				vQuestions.push_back(q);
			}
		}
	}
	else {
		cout << "\n\t\t 'data.txt' not found \n\n\n";
	}

	_f.close();

	//return vQuestions;
	return Shuffle(vQuestions);
}

vector<Player> readScores() {

	/*
	 * Argument: _f -- The text file containing your data
	 *
	 * Return: vPlayers -- return an ordered Player's scores vector
	 */

	ifstream _f("scores.txt", ios_base::in);

	vector<Player> vPlayers;

	if (_f.is_open()) {
		string name, scores;
		while (!_f.eof()) {
			getline(_f, scores, ',');
			getline(_f, name);
			Player p(name, atoi(scores.c_str()));
			vPlayers.push_back(p);
		}

		//sort element
		int n = vPlayers.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (vPlayers[i].getScores() < vPlayers[j].getScores()) {
					swap(vPlayers[i], vPlayers[j]);
				}
			}
		}

	}
	else {
		cout << "\n\t\t'scores.txt' not found\n";
	}

	_f.close();

	return vPlayers;
}



void leaderBoard() {
	vector<Player> vPlayers = readScores();
	int n = vPlayers.size();
	cout << "\n\n\t\t=========================================";
	cout << "\n\n\t\t\t       ACHIEVEMENT                  ";
	cout << "\n\n\t\t=========================================" << endl;
	cout << "\t\t*****************************************" << endl;

	for (int i = 0; i < n; i++) {
		cout << "\t\t" << i + 1 << ". "
			<< vPlayers[i].getName() << setw(15)
			<< vPlayers[i].getScores() << endl;
	}

	cout << "\t\t*****************************************" << endl;
	cout << "\n\t\tPress any key to continue";
}

void About() {
	cout << "\n\n\t\t=========================================";
	cout << "\n\n\t\t\t       DEVELOPED BY                 ";
	cout << "\n\n\t\t=========================================" << endl;
	cout << "\t\t*****************************************" << endl;
	cout << "\t\t*\tLecturer: Tran Nhat Hoang Anh   *" << endl;
	cout << "\t\t*\t - Nguyen Thien An              *" << endl;
	cout << "\t\t*\t - Le Thanh Dat                 *" << endl;
	cout << "\t\t*\t - Nguyen Nhi Thanh Le          *" << endl;
	cout << "\t\t*****************************************" << endl;
	cout << "\n\t\tPress any key to continue";

}

void menu(string user) {
	system(CLRSCR_CMD);
	cout << "\n\n\t\t         *********************";
	cout << "\n\n\t\t         *  Fun Puzzle Game  *";
	cout << "\n\n\t\t         *********************";
	cout << "\n\n\t\t====================================";
	cout << "\n\n\t\t\t    Welcome to " << user << "     ";
	cout << "\n\n\t\t====================================";
	cout << "\n\n";
	cout << "\t\t************************************" << endl;
	cout << "\t\t*\t 1. START                  *" << endl;
	cout << "\t\t*\t 2. ACHIEVEMENT            *" << endl;
	cout << "\t\t*\t 3. ABOUT                  *" << endl;
	cout << "\t\t*\t Any key to exit game      *" << endl;
	cout << "\t\t************************************" << endl;
}


#endif

