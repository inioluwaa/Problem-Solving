#include <iostream>
#include <string>

using namespace std;
int RabinKarp(const string &, const string &);

int main() {
    string t = "GACGCCA";
    string s = "GCC";

    int merger = RabinKarp(t, s);
    cout << merger;
}

// Returns the index of the first character of the substring if found, -1
// otherwise.
int RabinKarp(const string &t, const string &s) {
    if (s.size() > t.size()) {
        return -1;
    }

    const int kBase = 26;
    int t_hash = 0, s_hash = 0;     // Hash codes for the substrings of t and s.
    int power_s = 1;
    for (int i{0}; i < s.size(); ++i) {
        power_s = i ? power_s * kBase : 1;
        t_hash = t_hash * kBase + t[i];
        s_hash = s_hash * kBase + s[i];
    }

    for (int i = s.size(); i < t.size(); ++i) {
        // Check the two substrings are actually equal or not, to protect against
        // hash collision.
        if (t_hash == s_hash && !t.compare(i - s.size(), s.size(), s)) {
            return i - s.size();    // Found a match.
        }

        // Use rolling hash to compute the new hash code.
        t_hash -= t[i - s.size()] * power_s;
        t_hash = t_hash * kBase + t[i];
    }

    // Tries to match s and t[t.size() - s.size() : t.size() - 1].
    if (t_hash == s_hash && t.compare(t.size() - s.size(), s.size(), s) == 0) {
        return t.size() - s.size();
    }
    return -1;      // s is not a substring of t.
}