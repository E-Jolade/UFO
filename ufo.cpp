/*
6/24/2022 Emmanuel Jolade
UFO program emulates hangman, user inputs letters until they either guess the word correctly or run out of guesses. User will then be given the chance to play again and is shown the word at the end.
The codeword is picked from a collection of 5 words I chose in a vector and is randomly selected.
*/



#include <iostream>
#include "ufo_functions.h"
#include <stdlib.h>

using namespace std;

int main() {
	string codeword;
	string answer = "";
	int misses = 0;
	vector<char> incorrect;
	vector<string> potentialCodewords = { "persona", "valimar", "trails", "azure", "cassius"};
	bool guess = false;
	char letter;
	bool running = true;
	int menu;
	bool decision = true;
	srand(time(NULL));
	int chooser;


	do {
		answer = "";
		incorrect.clear();
		chooser = rand() % potentialCodewords.size();
		codeword = potentialCodewords.at(chooser);
		for (int i = 0; i < codeword.size(); i++) {
			answer += "_";
		}
		greet();

		while (answer != codeword && misses < 7) {
			displayMisses(misses);
			displayStatus(incorrect, answer);
			cout << "Please enter your guess: ";
			cin >> letter;
			tolower(letter);
			for (int i = 0; i < codeword.length(); i++) {
				if (codeword.at(i) == letter) {
					answer.at(i) = letter;
					guess = true;
				}
			}
			if (guess == true) {
				cout << "Correct!\n";
			}
			else {
				cout << "Incorrect! The tractor beam pulls the person in further.\n";
				incorrect.push_back(letter);
				misses++;
			}

			guess = false;

		}

		endGame(answer, codeword);

		cout << "Do you want to play again?\n\n";
		cout << "1.) Yes\n";
		cout << "2.) No\n";

		do
		{
			cin >> menu;
			if (menu == 1) {
				running = true;
				decision = false;
			}
			else if (menu == 2) {
				cout << "Thanks for playing!\n";
				running = false;
				decision = false;
			}
			else {
				cout << "Invalid input, try again\n";
			}
		} while (decision);
	} while (running);

}