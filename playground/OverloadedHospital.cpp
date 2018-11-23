#include <iostream>

using namespace std;

int totalCharges(int, double, double, double);
int totalCharges(double, double);

int main() {
    char admittedFor;
    int numOfDays;
    double dailyRates, medCharges, charges, totalCharge;
    cout << "Were you admitted as an impatient or an outpatient, Enter I for inpatient and O for outpatient" << endl;
    cin >> admittedFor;

    switch (admittedFor) {
        case 'i':
        case 'I': do {
                cout << "Enter the number of days" << endl;
                cin >> numOfDays;

                if (numOfDays < 0)
                    cout << "Number of days must be greater than 0" << endl;
            } while (numOfDays < 0);

            do {
                cout << "Enter the daily rates" << endl;
                cin >> dailyRates;

                if (dailyRates < 0)
                    cout << "Daily rates must be greater than 0" << endl;
            } while (numOfDays < 0);

        case 'o':
        case 'O':
            do {
                cout << "Enter the medical charges" << endl;
                cin >> medCharges;

                if (medCharges < 0)
                    cout << "Medical charges must be greater than 0" << endl;
            } while (medCharges < 0);

            do {
                cout <<"Enter the total charge" << endl;
                cin >> charges;

                if (charges < 0)
                    cout << "Charges should be greater than 0" << endl;
            } while (charges < 0);
    }
    switch (admittedFor) {
        case 'i':
        case 'I': totalCharge = totalCharges(numOfDays, dailyRates, medCharges, charges);

            cout << "number of days spent in the hospital: " << numOfDays << endl;
            cout << "daily rate: " << dailyRates << endl;

            break;
        case 'o':
        case 'O': totalCharge = totalCharges(medCharges, charges);
    }

    cout << medCharges << endl;
    cout << charges << endl;
    cout << totalCharge << endl;



}

int totalCharges(int days, double dailyRates, double medCharges, double charges) {
    return (days * dailyRates) + medCharges + charges;
}

int totalCharges(double medCharges, double charges) {
    return medCharges + charges;
}