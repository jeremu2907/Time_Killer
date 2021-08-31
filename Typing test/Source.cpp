/*
	Program name:	Typing test
	Date:			8-31-2021

	Typing test game
*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>

using namespace std;

int main() {
	//Seeding rand
	srand(time(NULL));

	//Read from file, creating output/input variable
	string target_word;
	string input;
	int wpm = 0;

	//Timer
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();

	//Initiating output
	while ((end - start).count() < 6*pow(10,10)) {
		ifstream vocablist("vocabulary.txt");

		//Random word generator
		int n = rand() % 4467;
		int line = 1;
		while (line < n) {
			++line;
			getline(vocablist, target_word);
		}
		
		//Display word and take user input
		do {
			cout << target_word << endl;
			cin >> input;
			
			system("CLS");	//Clearing terminal
			
		} while (input != target_word);

		++wpm;

		vocablist.close();
		end = std::chrono::high_resolution_clock::now();	//Updating how much time elapsed
	}
	cout << "WPM: " <<  wpm*2.1;
}
