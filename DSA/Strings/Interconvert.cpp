#include <iostream>

using namespace std;

int main() {
}

string IntToString (int x){
    bool is_negative = false;
    if (x < 0) {
        is_negative = true;
    }

    string s;
    do {
        s += '0' + abs(x % 10);
        x /= 10;
    } while (x);

    if (is_negative) {
        s += '-';
    }

    return {s.rbegin(), s.rend()};
}

int StringToInt (const string& s) {
    int result = 0;
    for (int i = s[0] == '-' ? 1 : 0; i < s.size(); ++i) {
        const int digit =  s[i] - '0';
        result = result * 10 + digit;
    }
    return s[0] == '-' ? -result : result;
}