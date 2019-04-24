#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
}

vector<int> Multiply(vector<int> num1, vector<int> num2) {
    int sign = num1.front() < 0 ^ num2.front() < 0 ? -1 : 1;
    num1.front() = abs(num1.front()), num2.front() = abs(num2.front());

    vector<int> result(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {

        }
    }
}
