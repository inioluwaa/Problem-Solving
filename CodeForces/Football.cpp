// Problem 96A - CodeForces - Football

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        int one = 0;
        int zero = 0;
        int ck = 0;

        for (int i {0}; i < n; i++) {
            if (s[i] == '0') {
                zero++;
                if (zero >= 7) {
                    ck = 1;
                    break;
                }
                one = 0;
            }
            else {
                one++;
                if (one >= 7) {
                    ck = 1;
                    break;
                }
                zero = 0;
            }
        }
        if (ck)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}