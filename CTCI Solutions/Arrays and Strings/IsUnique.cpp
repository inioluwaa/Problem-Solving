#include <iostream>
#include <string>
#include <array>
using namespace std;
bool isUniqueChars(string);

int main() {
    cout << isUniqueChars("qwerty");

}
bool isUniqueChars(string str) {
    if (str.size() > 128) return false;     // If we assume 128 characters -> ASCII
    array<bool, 128> char_set{};            // Create an array of boolean values.

    for (unsigned int i{0}; i < str.size(); i++) {
        int val = str.at(i);
        if (char_set[val]) return false;    // If the character has appeared twice, return false.
        char_set[val] = true;               // Appearing for the first time.
    }
    return true;
}