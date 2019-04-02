#include <iostream>
#include <string>
using namespace std;

int main() {
}

bool IsPalindrome(const string &s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool IsPalindrome(const string &s) {
    // i moves forward and j moves backward.
    int i = 0, j = s.size() - 1;
    while (i < j) {
        // i and j both skip non-alphanumeric characters.
        while (!isalnum(s[i]) && i < j) {
            ++i;
        }
        while (!isalnum(s[j]) && i < j) {
            --j;
        }
        if (tolower(s[i++]) != tolower(s[j--])) {
            return false;
        }
    }
    return true;
}


bool IsPalindrome(int num) {
    int save = num;
    int digit, reverse = 0;
    do {
        digit = num % 10;
        reverse = (reverse * 10) + digit;
        num = num / 10;
    } while (num != 0);

    return save = reverse;
}