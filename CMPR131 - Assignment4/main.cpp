#include "input.h"
#include "polynomials.h"

using namespace std;

void mainMenu();

int main()
{
    mainMenu();

    return 0;
}

// Pre-Condition: NA
// Post-Condition: no return. Main menu
void mainMenu()
{

    cout << endl;
    cout << "\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Otoniel Torres Bernal (9 / 21 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1> Complex Numbers" << endl;
    cout << "\t2> Rational Numbers" << endl;
    cout << "\t3> Polynomials" << endl;
    cout << "\t" << string(80, char(205));
    cout << "\n\t0 > EXIT" << endl;
    cout << "\t" << string(80, char(205)) << endl;

    // get user input/option of main menu
    int option = inputInteger("\tOption: ", 0, 3);

    // loop through main menu until user exits
    do
    {
        switch (option)
        {
        case 0: exit(1); break;
        case 1: system("cls");  break;
        case 2: system("cls");  break;
        case 3: system("cls"); Polynomial poly; poly.main();  break;

        }

        // new line
        cout << "\n";

    } while (true);
}