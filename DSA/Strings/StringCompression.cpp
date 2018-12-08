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

#include <iostream>
#include <string>

using namespace std;
int main() {
    int n;
    string s;

    cin >> s;
    n = s.size();
    for (int i {1}; i < n; ++i) {
        if (islower(s[i]))
            cout << s << endl;
    }
    if (islower(s[0])) {
        s[0] = toupper
    }
}

#include <iostream>
#include <string>

using namespace std;
int main() {
    int n;
    string s;

    cin >> s;
    n = s.size();
    for (int i {1}; i < n; ++i) {
        if (islower(s[i]))
            cout << s << endl;
    }
    if (islower(s[0])) {
        s[0] = toupper(s[0]);
    }
    else {
        s[0] = tolower(s[0]);
    }

    for (int i {1}; i < n; ++i) {
        s[i] = tolower(s[i]);
    }

    cout << s;
    return 0;
}