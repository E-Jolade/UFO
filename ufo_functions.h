#pragma once
#include <vector>
#include <string>

using namespace std; 

void greet();

void endGame(string answer, string codeword);

void displayMisses(int misses);

void displayStatus(vector<char> incorrect, string answer);