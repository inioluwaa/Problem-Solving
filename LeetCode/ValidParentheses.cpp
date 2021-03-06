#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;
bool isValid(string s);

int main() {
    cout <<  isValid("(()))))))");
}

/*bool check_key(unordered_map<char, char> T, char key) {
        if (T.find(key) == T.end())
            return false;
        return true;
    }*/

bool check_key(unordered_map<char, char> T, char key) {
    return !(T.find(key) == T.end());
}

bool isValid(string s) {
    unordered_map<char, char> T = { {')', '('},
                                    {'}', '{'},
                                    {']', '['} };
    stack<char> Stack{};
    for (char c : s) {
        if (check_key(T, c)) {
            if (Stack.empty()) {
                Stack.push('#');
            }
            if (Stack.top() == T[c]) {
                Stack.pop();
            } else {
                return false;
            }
        }
        else {
            Stack.push(c);
        }
    }
    return Stack.empty();
}

bool IsWellFormed(const string &s) {
    stack<char> unmatched{};
    for (char i : s) {
        if (i == '(' || i == '{' || i == '[') {
            unmatched.push(i);
        }
        else {
            if (unmatched.empty()) {
                return false;
            }
            if ( (i == ')' && unmatched.top() != '(') ||
                 (i == '}' && unmatched.top() != '{') ||
                 (i == ']' && unmatched.top() != '[')) {
                return false;
            }
            unmatched.pop();
        }
    }
    return unmatched.empty();
}
