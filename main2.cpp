#include <iostream>
#include <string>

using namespace std;
void ReverseEquation(string *);

int main() {

}

/*
numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"
 */


int minimumNumber(string password) {
    int n = password.size();
    // Return the minimum number of characters to make a strong password.
    for (unsigned int i{0}; i < n; ++i) {
        int lower = 0, higher = 0, digit = 0, specChar = 0;
        if (n < 6) {
            if (islower(password[i])) {
                lower++;
            }
            else if (isupper(password[i])) {
                higher++;
            }
            else if (isdigit(password[i])) {
                digit++;
            }
            else {
                specChar++;
            }


        }
        else {

        }
    }
}