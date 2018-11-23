#include <iostream>
#include <string>

using namespace std;

string compression(const string&);

int main() {
    string string1;
    cout << "Enter string for compression" << endl;
    cin >> string1;

    cout << "The compressed string is " << compression(string1);
}

string compression(const string& s) {
    string ret;
    if (s.size() == 0) {
        cout << "Empty string" << endl;
    }
    else {
        if (s.size() >= 1 && ret.size() < s.size()) {
            int n = s.size();

            ret[0] = s[0];

            for (int i = 0; i < n; i++) {
                int temp = 1;
                while (i < n - 1 && s[i] == s[i + 1]) {
                    temp++;
                    i++;
                }
                ret.push_back(s[i]);
                ret.push_back(static_cast<char>('0' + temp));
            }
            return ret;
        }
        else {
            return s;
        }
    }
}