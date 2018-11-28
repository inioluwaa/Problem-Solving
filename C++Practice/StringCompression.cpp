#include <iostream>
#include <string>

using namespace std;

string compression(const string&);

int main() {
    string string1, CompString;
    cout << "Enter string for compression" << endl;
    getline(cin, string1);
    CompString = compression(string1);
    if (!string1.empty()) {
        if (string1 == CompString)
            cout << "The string remains " << CompString << endl;
        else
            cout << "The compressed string is " << CompString;
    }
}

string compression(const string& s) {
    string ret;
    if (s.empty()) {
        cout << "Empty string" << endl;
    }
    else {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int temp = 1;
            while (i < n - 1 && s[i] == s[i + 1]) {
                temp++;
                i++;
            }
            if (temp == 1) {
                ret.push_back(s[i]);
            }
            else {
                ret.push_back(s[i]);
                ret.push_back(static_cast<char>('0' + temp));
            }
        }
    }
    return ret;
}