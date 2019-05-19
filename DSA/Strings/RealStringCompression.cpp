// RLE Compression (Encoding and Decoding)
// RLE - Run-length Encoding

#include <iostream>
#include <string>


using namespace std;

string Encoding1(const string &);
string Encoding2(const string &);
string Decoding1(const string &);
string Decoding2(const string &);
string Decoding3(const string &);

int main() {
    string s1 = "3t10f2d";
    string s2 = "t10f4d2";
    cout << Decoding3(s2);
}

string Encoding1(const string &s) {
    string result;
    int count = 1;
    for (int i{1}; i <= s.size(); ++i) {
        if (i == s.size() || s[i] != s[i - 1]) {
            // Found new character, so write the count of previous character.
            result += s[i - 1] + to_string(count);
            count = 1;
        }
        else /* s[i] == s[i - 1]*/ {
            ++count;
        }
    }
    return result;
}

// Encoding but only outputs the values greater than 1.
string Encoding2(const string &s) {
    string result;
    int count = 1;
    for (int i{1}; i <= s.size(); ++i) {
        if (i == s.size() || s[i] != s[i - 1]) {
            if (count == 1) {
                result += s[i - 1];
                count = 1;
            }
            else {
                result += s[i - 1] + to_string(count);
                count = 1;
            }
        }
        else /* s[i] == s[i - 1]*/ {
            count++;
        }
    }
    // If compressed string is greater than input string, output the input string
    if (result.size() > s.size()) return s;
    else return result;
}

string Compression2(const string &s) {
    string compressed;
    int count = 1;
    for (int i = 1; i <= s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            ++count;
        }
        else {
            compressed += s[i - 1] + to_string(count);
            count = 1;
        }
    }
    return compressed;
}

// 3t4f2d
// Number-first decoding
string Decoding1(const string &s) {
    unsigned int count = 0;
    string result;
    for (const char &c : s) {
        if (isdigit(c)) {
            count = count * 10 + c - '0';
        }
        else {
            result.append(count, c);
            count = 0;
        }
    }
    return result;
}

// t3f4d2
// Letter-first decoding
string Decoding2(const string &s) {
    unsigned int count = 0;
    char c;
    string result;
    for (auto i{0}; i < s.size(); ++i) {
        if (isalpha(s[i])) {
            c = s[i];
            count = 0;
        }
        else {
            count = count * 10 + s[i] - '0';
        }
        result.append(count, c);
    }
    return result;
}

// t3f4d2
// Letter-first decoding 2(Alternate method)
string Decoding3(const string &s) {
    unsigned int count = 0;
    char c;
    string result;
    for (auto i{0}; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            count = count * 10 + s[i] - '0';
        }
        else {
            c = s[i];
            count = 0;
        }
        result.append(count, c);
    }
    return result;
}

