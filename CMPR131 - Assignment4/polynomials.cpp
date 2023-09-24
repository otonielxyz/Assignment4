#include "polynomials.h"
#include "input.h"
#include <cmath>
#include <iostream>

Polynomial::Polynomial() {}

void Polynomial::enterTerms() {
    int numTerms;
    numTerms = inputInteger("Enter the number of terms(1.. 100) for the polynomial: ", 1, 100);
    coefficients.resize(numTerms);
    termsEntered = true;
}

void Polynomial::specifyCoefficients() {
    for (size_t i = coefficients.size(); i > 0; --i) {
        string prompt = "Enter the coefficient for term #" + to_string(coefficients.size() - i + 1) + ": ";
        coefficients[i - 1] = inputDouble(prompt);
    }
    coefficientsSpecified = true;
    cout << "\nThe P(x) is entered: ";
    printPolynomial(*this);
}

double Polynomial::evaluateExpression(double x) {
    double result = 0;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::derivative() {
    Polynomial deriv;
    for (size_t i = 1; i < coefficients.size(); ++i) {
        deriv.coefficients.push_back(i * coefficients[i]);
    }
    return deriv;
}

Polynomial Polynomial::integral() {
    Polynomial integral;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        integral.coefficients.push_back(coefficients[i] / (i + 1));
    }
    return integral;
}

void Polynomial::main() {

    char choice = ' ';

    do {
        cout << "\tPolynomial Calculator\n";
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\tA> Single Polynomial\n";
        cout << "\tB> Multiple Polynomials\n";
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\t0 > Return\n";
        cout << "\t" << string(80, char(205)) << endl;
        choice = toupper(inputChar("\tOption: ", static_cast<std::string>("AB0)")));

        switch (choice) {
        case 'A': {
            system("cls");
            runSinglePolynomialMenu();
            break;
        }
        case 'B': {
            system("cls");
            runMultiplePolynomialsMenu();
            break;
        }
        case '0': 
            system("cls");
            mainMenu();
            break;
        default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '0');
}

void Polynomial::runSinglePolynomialMenu() {
    int choice;
    do {
        cout << "\tSingle Polynomial\n";
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\t1. Enter the number of terms\n"; // done
        cout << "\t2. Specify the coefficients\n";
        cout << "\t3. Evaluate expression\n";
        cout << "\t4. Solve for the derivative\n";
        cout << "\t5. Solve for the integral\n";
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\t0. Return\n";
        cout << "\t" << string(80, char(205)) << endl;
        choice = inputInteger("\tOption: ");

        switch (choice) {
        case 1: // done
            system("cls");
            enterTerms(); 
            break;
        case 2: // done
            system("cls");
            if (!termsEntered) {
                cerr << "Error: Please enter the number of terms first.\n";
                break;
            }
            specifyCoefficients(); 
            break;
        case 3: { // done 
            system("cls");
            if (!termsEntered) {
                cerr << "Error: Please enter the number of terms first.\n";
                break;
            }
            if (!coefficientsSpecified) {
                cout << "Error: Please specify the coefficients first.\n";
                break;
            }
            cout << "P1(x) = ";
            printPolynomial(*this);
            double x;
            cout << "\nEnter the value of x to evaluate the polynomial: ";
            cin >> x;
            cout << endl;

            double total = 0;
            for (int i = coefficients.size() - 1; i >= 0; --i) {
                double term_value = coefficients[i] * pow(x, i);
                total += term_value;
                cout << setw(12) << right << term_value << " <- " << setw(10) << coefficients[i] << "x^" << i << endl;
            }
            cout << string(40, char(205)) << endl;
            cout << setw(22) << right << total << endl;
            break;
        }
        case 4: { //
            system("cls");
            if (!termsEntered) {
                cerr << "Error: Please enter the number of terms first.\n";
                break;
            }
            if (!coefficientsSpecified) {
                cout << "Error: Please specify the coefficients first.\n";
                break;
            }
            Polynomial deriv = derivative();
            printPolynomial(deriv);
            break;
        }
        case 5: { //
            system("cls");
            if (!termsEntered) {
                cerr << "Error: Please enter the number of terms first.\n";
                break;
            }
            if (!coefficientsSpecified) {  
                cout << "Error: Please specify the coefficients first.\n";
                break;
            }
            Polynomial integralResult = integral();
            printPolynomial(integralResult);
            break;
        }
        case 0: 
            system("cls");
			main();
        break;
        default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

void Polynomial::printPolynomial(const Polynomial& poly) {
    for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
        // Handle the first term separately to avoid the leading + sign
        if (i == poly.coefficients.size() - 1) {
            if (poly.coefficients[i] < 0) {
                cout << "- ";
            }
        }
        else {
            if (poly.coefficients[i] >= 0) {
                cout << "+ ";
            }
            else {
                cout << "- ";
            }
        }
        // Print the absolute value of the coefficient, the variable x, and the exponent
        if (i > 1) {
            cout << abs(poly.coefficients[i]) << "x^" << i << " ";
        }
        else if (i == 1) {
            cout << abs(poly.coefficients[i]) << "x" << " ";
        }
        else {
            cout << abs(poly.coefficients[i]) << " ";
        }
    }
    cout << endl;
}

Polynomial Polynomial::add(const Polynomial& p) const {
    int max_degree = std::max(this->coefficients.size(), p.coefficients.size());
    Polynomial result;
    result.coefficients.resize(max_degree, 0);

    for (size_t i = 0; i < this->coefficients.size(); ++i) {
        result.coefficients[i] += this->coefficients[i];
    }

    for (size_t i = 0; i < p.coefficients.size(); ++i) {
        result.coefficients[i] += p.coefficients[i];
    }

    return result;
}

Polynomial Polynomial::subtract(const Polynomial& p) const {
    int max_degree = max(this->coefficients.size(), p.coefficients.size());
    Polynomial result;
    result.coefficients.resize(max_degree, 0);

    for (size_t i = 0; i < this->coefficients.size(); ++i) {
        result.coefficients[i] += this->coefficients[i];
    }

    for (size_t i = 0; i < p.coefficients.size(); ++i) {
        result.coefficients[i] -= p.coefficients[i];
    }

    return result;
}

Polynomial Polynomial::multiply(const Polynomial& p) const {
    int max_degree = (this->coefficients.size() - 1) + (p.coefficients.size() - 1) + 1;
    Polynomial result;
    result.coefficients.resize(max_degree, 0);

    for (size_t i = 0; i < this->coefficients.size(); ++i) {
        for (size_t j = 0; j < p.coefficients.size(); ++j) {
            result.coefficients[i + j] += this->coefficients[i] * p.coefficients[j];
        }
    }

    return result;
}

Polynomial Polynomial::scalarMultiply(double scalar) const {
    Polynomial result;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result.coefficients.push_back(coefficients[i] * scalar);
    }
    return result;
}
void Polynomial::runMultiplePolynomialsMenu() {
    cout << "\tTwo Polynomials\n";
    cout << "\t" << string(80, char(205)) << endl;
    Polynomial p1, p2, result;
    p1.enterTerms();
    p1.specifyCoefficients();
    cout << "\nThe first polynomial (P1) is entered: ";
    printPolynomial(p1);

    p2.enterTerms();
    p2.specifyCoefficients();
    cout << "\nThe second polynomial (P2) is entered: ";
    printPolynomial(p2);

    cout << "\n\tOperations:\n";
    cout << "\t" << string(80, char(205)) << endl;

    result = p1.add(p2);
    cout << "\tAddition of polynomials       -> P1 + P2 = ";
    printPolynomial(result);

    result = p1.subtract(p2);
    cout << "\tSubtraction of polynomials    -> P1 - P2 = ";
    printPolynomial(result);

    result = p1.multiply(p2);
    cout << "\tMultiplication of polynomials -> P1 * P2 = ";
    printPolynomial(result);

    double scalar;
    cout << "\n\tEnter a constant value: ";
    cin >> scalar;

    result = p1.scalarMultiply(scalar);
    cout << "\t" << scalar << " * Polynomial(P1) = ";
    printPolynomial(result);

    result = p2.scalarMultiply(scalar);
    cout << "\tPolynomial(P2) * " << scalar << " = ";
    printPolynomial(result);

    system("pause");
}