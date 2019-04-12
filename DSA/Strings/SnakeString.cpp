#include <iostream>
#include <string>
using namespace std;

string SnakeString(const string &);
int main() {
    string s = "Hello World";
    cout << SnakeString(s);
}

string SnakeString(const string &s) {
    string result;

    // Outputs the first row, i.e., s[1], s[5], s[9], ...
    for (int i{1}; i < s.size(); i += 4) {
        result += s[i];
    }

    // Outputs the second row, i.e., s[0], s[2], s[4], ...
    for (int i{0}; i < s.size(); i += 2) {
        result += s[i];
    }

    // Outputs the third row, i.e., s[3], s[7], s[11], ...
    for (int i{3}; i < s.size(); i += 4) {
        result += s[i];
    }
    return result;
}