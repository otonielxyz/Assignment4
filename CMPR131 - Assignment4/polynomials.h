#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // for std::setw and std::right
#include "input.h"  // assumed this is where inputDouble and inputInteger are defined

using namespace std;

void mainMenu();

class Polynomial {
private:
    vector<double> coefficients;
    bool termsEntered = false;
    bool coefficientsSpecified = false;

public:
    Polynomial();

    void enterTerms();
    void specifyCoefficients();
    double evaluateExpression(double x);
    Polynomial derivative();
    Polynomial integral();
    void printPolynomial(const Polynomial& poly);

    void main();
    void runSinglePolynomialMenu();

    Polynomial add(const Polynomial& p) const;
    Polynomial subtract(const Polynomial& p) const;
    Polynomial multiply(const Polynomial& p) const;
    Polynomial scalarMultiply(double scalar) const;
    void runMultiplePolynomialsMenu();
};
