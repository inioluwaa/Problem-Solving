// Problem 112A - CodeForces - Petya and Strings

#include <iostream>
#include <string>

using namespace std;

int main() {
    string string1, string2;
    cin >> string1;
    cin >> string2;
    int n = string1.size();

    for (int i = 0; i < n; ++i) {
        string1[i] = tolower(string1[i]);
    }

    for (int j = 0; j < n; ++j) {
        string2[j] = tolower(string2[j]);
    }

    if (string1 > string2)
        cout << 1 << endl;
    else if (string1 < string2)
        cout << -1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
