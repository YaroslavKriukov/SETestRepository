#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

void calculate() {
    int n, k = 1;
    double a, b, step, x, y;

    while (true) {
        cout << "Input n (integer, n >= 4): ";
        double tempN;
        if (!(cin >> tempN)) {
            cout << "[Error] Invalid input for n. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (floor(tempN) != tempN) {
            cout << "[Error] n must be an integer." << endl;
            continue;
        }
        n = static_cast<int>(tempN);
        if (n < 4) {
            cout << "[Error] n must be >= 4." << endl;
            continue;
        }
        break;
    }  

  
    while (true) {
        cout << "Input range a b (a <= b): ";
        if (!(cin >> a >> b)) {
            cout << "[Error] Invalid input for range. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (a > b) {
            cout << "[Error] Range invalid: a must be <= b." << endl;
            continue;
        }
        break;
    }


    if (a > b) {
        cout << "[Error] Range is invalid: a must be <= b." << endl;
        return;
    }

    while (true) {
        cout << "Input step (s > 0): ";
        if (!(cin >> step)) {
            cout << "[Error] Invalid input for step. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (step <= 0) {
            cout << "[Error] Step must be positive." << endl;
            continue;
        }
        break;
    }


    cout << "Results of calculation" << endl;
    cout << "---------------------------" << endl;
    cout << setw(8) << "xk" << setw(18) << "yk" << endl;
    cout << "---------------------------" << endl;

    bool hasResults = false;

    for (x = a; x <= b; x += step) {
        y = 0.0;

        if (x <= -5.0) {
            double sum = 0.0;
            for (int i = -6; i <= n; i++) {
                sum += (i + x);
            }
            y = 4.0 * x * sum - 9.0;
        }
        else {
            double denom = 4.0 + x * x;
            for (int i = 1; i <= n; i++) {
                double prod = 1.0;
                for (int j = 0; j <= n - 3; j++) {
                    prod *= ((i - 2.0 * j) / denom);
                }
                y += prod;
            }
        }

        cout.setf(ios::fixed);
        cout.precision(5);
        cout << "x" << k << " = " << setw(6) << x
            << "; y" << k << " = " << setw(10) << y << endl;
        k++;
        hasResults = true;
    }

    if (!hasResults) {
        cout << "[Info] No results for the given range and step." << endl;
    }
}

void help() {
    cout << "Help:" << endl;
    cout << "This program calculates y for n >= 4 over a range (a, b) with a given step." << endl;
    cout << "Formula used:" << endl;
    cout << "If x <= -5: y = 4*x * Sigma(i=-6..n)(i+x) - 9" << endl;
    cout << "If x > -5:  y = Sigma(i=1..n)( Pi(j=0..n-3)( (i-2j)/(4 + x^2) ) )" << endl;
    cout << "Notation: Sigma = sum, Pi = multiplication" << endl;
}

int main() {
    int choice = 0;
    do {
        cout << "\n==============================" << endl;
        cout << "   Function Calculator v1.0" << endl;
        cout << "==============================" << endl;
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
        case 1: calculate(); break;
        case 2: help(); break;
        case 3: cout << "Goodbye!" << endl; break;
        }
    } while (choice != 3);

    return 0;
}                     // 12312321321321321321321321312321312312313213212312213
