#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int numOfEmployees();
int numOfDaysMissed(int);
double avgNumOfDaysAbs(int, int);

int main() {
    cout << fixed << showpoint << setprecision(2);
    int numEmp = numOfEmployees();
    int numMissed = numOfDaysMissed(numEmp);
    double avgDays = avgNumOfDaysAbs(numEmp, numMissed);

}

int numOfEmployees() {
    int numEmp;

    do {
        cout << "How many employees are in the company" << endl;
        cin >> numEmp;

        if(numEmp < 1)
            cout << "Error" << endl;
    }
    while(numEmp < 1);
    return numEmp;
}

int numOfDaysMissed(int numOfEmps) {
    int numMissed;
    int total = 0;
    for (int i = 1; i <= numOfEmps; i++) {
        cout << "Enter the number of days missed by Employee " << i << endl;
        cin >> numMissed;
        total += numMissed;
    }
    return total;
}

double avgNumOfDaysAbs(int numOfEmps, int numMissed) {
    double avg;
    cout << "Values  "<< numOfEmps << numMissed << endl;
    avg = numMissed / numOfEmps;
    cout << "the average is " << avg << endl;
    return avg;
}