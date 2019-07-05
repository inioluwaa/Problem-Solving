#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsGreaterOrEqual (string a, string b) {
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0;
}

string largest_number(vector<string> a) {
    string result;
    while (!a.empty()) {
        int maxDigit = 0;
        for (int i(1); i < a.size(); ++i) {
            if (IsGreaterOrEqual(a[i], a[maxDigit]))
                maxDigit = i;
        }
        result.append(a[maxDigit]);
        auto itr = find(a.begin(), a.end(), a[maxDigit]);
        if (itr != a.end()) a.erase(itr);
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
    /* cout << IsGreaterOrEqual("23", "21");*/
}
