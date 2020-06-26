#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <iomanip>

using namespace std;

class Questions {
private:
	string question, questionType, trueAns;
	string answer1, answer2, answer3, answer4;

public:
	Questions(string _question, string _questionType, string _answer1, string _answer2, string _answer3, string _answer4, string _trueAns) {

		this->question = _question;
		this->questionType = _questionType;

		if (!this->questionType.compare("M")) {
			this->answer1 = _answer1;
			this->answer2 = _answer2;
			this->answer3 = _answer3;
			this->answer4 = _answer4;
		}
		this->trueAns = _trueAns;
	}

	Questions(string _question, string _questionType, string _trueAns) {
		this->question = _question;
		this->questionType = _questionType;
		this->trueAns = _trueAns;
	}

	bool checkAnswer(string myAnswer) {
		if (!myAnswer.compare(this->trueAns)) {
			return true;
		}
		return false;
	}

	void display() {
		string ansName[4] = { "A. ", "B. ", "C. ", "D. " };

		cout << this->question << endl;
		if (!this->questionType.compare("M")) {
			cout << "\t" << setw(20) << ansName[0] << this->answer1
				<< setw(20) << ansName[1] << this->answer2 << endl;
			cout << "\t" << setw(20) << ansName[2] << this->answer3
				<< setw(20) << ansName[3] << this->answer4 << endl;

			cout << "\n\t\t\tYour answer: ";

			return;
		}
		else {
			if (!this->questionType.compare("T")) {
				cout << "\t" << setw(20) << "True (T)" << setw(20) << "False (F)" << endl;
				cout << "\n\t\t\tYour answer: ";
				return;
			}
			else cout << "\n\t\t\tYour answer: ";
		}
	}



	//getter/setter
	string getQuestion() { return this->question; }
	string getType() { return this->questionType; }
	string getTrueAns() { return this->trueAns; }
};

#endif // QUESTIONS_H
