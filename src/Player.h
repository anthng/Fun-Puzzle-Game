#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
private:
	string name = "bot";
	int scores = 0;
public:
	Player(string _name, int _scores) {
		this->name = _name;
		this->scores = _scores;
	}
	Player() {
		this->name = "bot";
		this->scores = 0;
	}

	string getName() {
		return this->name;
	}

	int getScores() {
		return this->scores;
	}

	void setName(string _name) {
		this->name = _name;
	}

	void setScores(int _scores) {
		this->scores = _scores;
	}

	void addScores(int _scores) {
		this->scores += _scores;
	}

	void recordScores(ofstream &f) {
		f.open("scores.txt", ios_base::app);
		if (f.is_open()) {
			f << this->scores << "," << this->name << "\n";
		}
		else {
			cout << "\n\t\t'scores.txt' not found\n";
			f.close();
			return;
		}
		f.close();
	}

	~Player() {
	}

};

#endif // PLAYER_H
