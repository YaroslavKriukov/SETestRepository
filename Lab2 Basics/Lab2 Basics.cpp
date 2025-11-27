#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string> 
using namespace std;

void checkValidInput()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw "Incorrect input: Expected a number or integer.";
    }
}

void checkValidN(int n)
{
    if (n < 4)
    {
        throw "Input correct data: N must be >= 4.";
    }
}

void calculate(int n, double a, double b, double step)
{
    double y = 0.0;
    bool hasResults = false;

    cout.setf(ios::fixed);
    cout.precision(5);
    cout << setw(8) << "xk" << setw(18) << "yk" << endl;
    cout << "-----------------------------------" << endl;

    for (double x = a; x <= b; x += step) {
        y = 0.0;

        if (x <= -5.0) {
            double sum = 0.0;
            for (int i = 6; i <= n; i++) {
                sum += (i + x);
            }
            y = 4.0 * x * sum - 9.0;
        }

        else {
            double denom = 4.0 + x * x;
            double prod = 1.0;
            for (int j = 0; j <= n - 3; j++) {
                prod *= ((1.0 - 2.0 * j) / denom);
            }
            y = prod;
        }

        cout << setw(8) << x << setw(18) << y << endl;
        hasResults = true;
    }

    if (!hasResults) {
        cout << "[Info] No results for the given range and step." << endl;
    }
}

void help()
{
    cout << "Help:" << endl;
    cout << "This program calculates y for n >= 4 over a range (a, b) with a given step." << endl;
}

int main()
{
    int choice = 0;

    do {
        cout << "n========================" << endl;
        cout << "Function Calculator v1.0" << endl;
        cout << "========================" << endl;
        cout << "1. Calculate function" << endl;
        cout << "2. Help" << endl;
        cout << "3. Exit" << endl;
        cout << "Select option: ";

        double tempChoice;
        if (!(cin >> tempChoice)) {
            cout << "[Error] Invalid input. Please enter a number (1-3)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (floor(tempChoice) != tempChoice) {
            cout << "[Error] Option must be an integer (1, 2, or 3)." << endl;
            continue;
        }

        choice = static_cast<int>(tempChoice);

        if (choice < 1 || choice > 3) {
            cout << "[Error] Invalid option. Enter 1, 2, or 3." << endl;
            continue;
        }

        switch (choice) {
        case 1:

        {
            int n;
            double a, b, step, tempN;
            try {


                cout << "Input n (integer, n >= 4): ";
                if (!(cin >> tempN)) {
                    checkValidInput();
                }
                if (floor(tempN) != tempN) {
                    throw "Error: N must be an integer.";
                }
                n = static_cast<int>(tempN);
                checkValidN(n);


                cout << "Input range a b (a <= b): ";
                if (!(cin >> a >> b)) {
                    checkValidInput();
                }
                if (a > b) {
                    throw "Error: Range invalid: a must be <= b.";
                }


                cout << "Input step (s > 0): ";
                if (!(cin >> step)) {
                    checkValidInput();
                }
                if (step <= 0) {
                    throw "Error: Step must be positive.";
                }


                calculate(n, a, b, step);

            }

            catch (const char* ex) {
                cout << "[ERROR] " << ex << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            catch (...) {
                cout << "[ERROR] Unknown fatal error." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        break;
        case 2: help(); break;
        case 3: cout << "Goodbye!" << endl; break;
        }
    } while (choice != 3);

    return 0;
}