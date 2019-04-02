#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
bool permutation2(const string &S, string T);

int main() {
    cout << permutation2("cata", "acta");
}

// Solution 1
/*bool permutation(string S, string T) {
    if (S.size() != T.size()) return false;         // Compare length of both string if equal.

    sort(S.begin(), S.end());                       //Sort strings.
    sort(T.begin(), T.end());

    return S == T;
}*/

// Solution 2
bool permutation2(const string &S, string T) {
    if (S.size() != T.size()) return false;

    array<int, 128> letters{};
    int n = S.size();
    char* char_array = char[n+1];


    strcpy(char_array, S.c_str());
    for (char c : char_array) {
        letters[c]++;
    }

    for (unsigned int i{0}; i < T.size(); i++) {
        int c = T.at(i);
        letters[c]--;
        if (letters[c] < 0) return false;
    }
}


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>


using namespace std;
bool permutation2(const string &S, string T);

int main() {
    cout << permutation2("cata", "cata");
}

// Solution 1
/*bool permutation(string S, string T) {
    if (S.size() != T.size()) return false;         // Compare length of both string if equal.

    sort(S.begin(), S.end());                       //Sort strings.
    sort(T.begin(), T.end());

    return S == T;
}*/

// Solution 2
bool permutation2(const string &S, string T) {
    if (S.size() != T.size()) return false;

    array<int, 128> letters{};
    size_t n = S.size();
    char* char_array{new char[n+1]};

    S.copy(char_array, n, 0);
    char_array[n] = '\0';

    for (size_t c{0}; c < n; ++c) {
        letters[c]++;
    }

    for (unsigned int i{0}; i < T.size(); i++) {
        int c = T.at(i);
        letters[c]--;
        if (letters[c] < 0) return false;
    }
}