#include <iostream>

using namespace std;

int getNumOfAccidents(string);

void findLowest(double, double, double, double);

int main() {
    int North, South, East, West, Central;

    cout << "Enter the number of accidents" << endl;
    North = getNumOfAccidents("North");
    South = getNumOfAccidents("South");
    East = getNumOfAccidents("East");
    West = getNumOfAccidents("West");
    Central = getNumOfAccidents("Central");

    findLowest(North, South, East, West, Central);

}

int getNumOfAccidents(string region) {
    int total;
    do {
        cout << "What is the number of accidents for the " << region << endl;
        cin >> total;

        if (total < 0)
            cout << "Error, must be greater than 0" << endl;

    }
    while (total < 0);
        return total;
}

void findLowest(double reg1, double reg2, double reg3, double reg4, double reg5) {
    cout << "The lowest is ";
    if (reg1 < reg2, reg1 < reg3, reg1 < reg4, reg1 < reg5)
        cout << "North" << endl;
    else if (reg2 < reg1, reg2 < reg3, reg2 < reg4, reg2 < reg < reg5)
        cout << "South" << endl;
    else if (reg3 < reg1, reg3 < reg2, reg3 < reg4, reg3 < reg5)
        cout << "East" << endl;
    else if (reg4 < reg1, reg4 < reg2, reg4 < reg3, reg4 < reg5)
        cout << "West" << endl;
    else
        cout << "Central" << endl;
}