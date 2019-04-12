#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
bool IsValidPart(const string &);
vector<string> GetValidIPAddress(const string &);

int main() {

}

bool IsValidPart(const string &s) {
    if (s.size() > 3) {
        return false;
    }
    // "00", "000", "01", etc. are not valid, but "0" is valid.
    if (s.front() == '0' && s.size() > 1) {
        return false;
    }
    int val = stoi(s);
    return val <= 255 && val >= 0;
}

// "19216811"
vector<string> GetValidIPAddress(const string &s) {
    vector<string> result;
    for (size_t i{1}; i < 4 && i < s.size(); ++i) {
        const string first = s.substr(0, i);
        if (IsValidPart(first)) {
            for (size_t j{1}; i + j < s.size() && j < 4; ++j) {
                const string second = s.substr(i, j);
                if (IsValidPart(second)) {
                    for (size_t k{1}; i + j + k < s.size() && k < 4; ++k) {
                        const string third = s.substr(i + j, k),
                                fourth = s.substr(i + j + k);
                        if (IsValidPart(third) && IsValidPart(fourth)) {
                            result.emplace_back(first + "." + second + "." +
                                                third + "." + fourth);
                        }
                    }
                }
            }
        }
    }
    return result;

}