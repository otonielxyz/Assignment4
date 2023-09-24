#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string inputString(string prompt, bool spaces);
char inputChar(string prompt, string options);
char inputChar(string prompt, char yes, char no);
char inputChar(string prompt, bool alphaOrDigit);
char inputChar(string prompt);
int inputInteger(string prompt);
int inputInteger(string prompt, bool posNeg);
int inputInteger(string prompt, int start, bool greater);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);
double inputDouble(string prompt, bool posNeg);
double inputDouble(string prompt, double start, bool posNeg);
double inputDouble(string prompt, double startRange, double endRange);
