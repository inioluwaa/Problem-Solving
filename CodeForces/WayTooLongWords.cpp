#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;
        if (word.size() > 10 && word.size() <= 100)
            cout << word[0] << word.size() - 2 << word.back() << endl;
        else
            cout << word << endl;
    }
}