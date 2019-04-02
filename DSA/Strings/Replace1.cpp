#include <iostream>
#include <string>
using namespace std;
void Replace(char [], int);

int main() {
}

void Replace(char s[], int TrueSize) {
    int a_count = 0, index;
    for (int i{0}; i < TrueSize; ++i) {
        if (s[i] == 'a') {
            a_count++;
        }
    }
    cout << "\na count is " << a_count << endl;


    index = TrueSize + a_count;
    for (int i = TrueSize - 1; i >= 0; ++i) {
        if (s[i] == 'a') {
            s[index--] = 'd';
            s[index--] = 'd';
        }
        else {
            s[index--] = s[i];
        }
    }
}