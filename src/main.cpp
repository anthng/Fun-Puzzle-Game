#include <iostream>
#include <fstream>

#include "Questions.h"
#include "Player.h"
#include "utils.h"
#include "Controller.h"

using namespace std;

int main() {
	ifstream fData("data.txt", ios_base::in);

	vector<Questions> vQuestions;

	vQuestions = readFile(fData);

	Controller(vQuestions);

	return 0;
}