#include <iostream>
#include <string>

using namespace std;
void ReverseEquation(string *);

int main() {
    string *EquPtr{nullptr};
    string s = "100+400-300*200/600*5000";
    EquPtr = &s;
    ReverseEquation(EquPtr);

    cout << *EquPtr;
}

void ReverseEquation(string *EquPtr) {
    reverse(EquPtr->begin(), EquPtr->end());
    size_t start = 0, end;

    while ((end = EquPtr->find_first_of("+-*/", start)) != string::npos) {
        reverse(EquPtr->begin() + start, EquPtr->begin() + end);
        start = end + 1;
    }
    reverse(EquPtr->begin() + start, EquPtr->end());
}