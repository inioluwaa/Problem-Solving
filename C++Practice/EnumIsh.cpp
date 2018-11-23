#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
    char ch;
    etype chosen;
    int che;

    cout << "Enter employee type " << endl;
    cin >> ch;

    switch (ch) {
        case 'l':
            chosen = laborer;
            break;
        case 's':
            chosen = secretary;
            break;
        case 'm':
            chosen = manager;
            break;
        case 'a':
            chosen = accountant;
            break;
        case 'e':
            chosen = executive;
            break;
        case 'r':
            chosen = researcher;
            break;
    }
    switch (chosen) {
        case 0:
            cout << "Employee type is labourer";
            break;
        case 1:
            cout << "Employee type is secretary";
            break;
        case 2:
            cout << "Employee type is manager";
            break;
        case 3:
            cout << "Employee type is accountant";
            break;
        case 4:
            cout << "Employee type is executive";
            break;
        case 5:
            cout << "Employee type is researcher";
            break;
    }
}