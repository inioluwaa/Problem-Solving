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

// Reverse all the words in a sentence... Alice likes Bob -> Bob likes Alice.
// Using Pointers.
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

// Reverses all the numbers in an equation.. 100+400-300 -> 300-400+100
// Using Pointers.
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

// Reverses all the numbers in an equation.. 100+400-300 -> 300-400+100
// Using References.
void ReverseEquation(string &EquPtr) {
    // Reverses the whole string first.
    reverse(EquPtr.begin(), EquPtr.end());
    size_t start = 0, end;

    while ((end = EquPtr.find_first_of("+-*/", start)) != string::npos) {
        // Reverses each word in the string but not the last word.
        reverse(EquPtr.begin() + start, EquPtr.begin() + end);
        start = end + 1;
    }
    // Reverses the last word.
    reverse(EquPtr.begin() + start, EquPtr.end());
}
