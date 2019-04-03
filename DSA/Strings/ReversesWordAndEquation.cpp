#include <iostream>
#include <string>

using namespace std;

int main() {
    string *EquPtr{nullptr};
    string s = "100+400-300*200/600*5000";
    EquPtr = &s;
    ReverseEquation(EquPtr);
    cout << *EquPtr;
}

void ReverseWords(string *sPtr) {
    // Reverses the whole string first.
    reverse(sPtr->begin(), sPtr->end());

    size_t start = 0, end;
    while ((end = sPtr->find(" ", start)) != string::npos) {
        // Reverses each word in the string.
        reverse(sPtr->begin() + start, sPtr->begin() + end);
        start =  end + 1;
    }
    // Reverses the last word.
    reverse(sPtr->begin() + start, sPtr->end());
}

void ReverseEquation(string *EquPtr) {
    // Reverses the whole string first.
    reverse(EquPtr->begin(), EquPtr->end());
    size_t start = 0, end;

    while ((end = EquPtr->find_first_of("+-*/", start)) != string::npos) {
        // Reverses each word in the string but not the last word.
        reverse(EquPtr->begin() + start, EquPtr->begin() + end);
        start = end + 1;
    }
    // Reverses the last word.
    reverse(EquPtr->begin() + start, EquPtr->end());
}
