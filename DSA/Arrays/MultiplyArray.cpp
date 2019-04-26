#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> Multiply(vector<int>, vector<int>);

int main() {
    vector<int> num1 {1, 9, 3, 7, 0, 7, 7, 2, 1};
    vector<int> num2 {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
    vector<int> num3 = Multiply(num1, num2);
    for (auto i : num3) {
        cout << i << " ";
    }

}

vector<int> Multiply(vector<int> num1, vector<int> num2) {
    int sign = num1.front() < 0 ^ num2.front() < 0 ? -1 : 1;
    num1.front() = abs(num1.front()), num2.front() = abs(num2.front());

    vector<int> result(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            result[i + j + 1] += num1[i] * num2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    result = {find_if_not(begin(result), end(result), [](int a) { return a == 0;}),
              end(result)};
    if (result.empty()) {
        return {0};
    }
    result.front() *= sign;
    return result;
}
