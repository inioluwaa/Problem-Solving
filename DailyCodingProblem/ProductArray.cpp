/* Daily Coding Problem 2

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array
is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> ProductArray2(vector<int>);

int main() {
    vector<int> u = {1, 2, 3, 4, 5};
    vector<int> v = ProductArray2(u);
    for (auto i : v) {
        cout << i << " ";
    }

}

vector<int> ProductArray(vector<int> arr) {
    int n = arr.size();
    vector<int> left_array (n);
    vector<int> right_array (n);
    vector<int> prod (n);

    left_array[0] = 1;
    right_array[n - 1] = 1;

    for (int i(1); i < n; ++i) {
        left_array[i] = arr[i - 1] * left_array[i - 1];
    }
    for (int j(n - 2); j >= 0; --j) {
        right_array[j] = arr[j + 1] * right_array[j + 1];
    }

    for (int i(0); i < n; ++i) {
        prod[i] = left_array[i] * right_array[i];
    }
    return prod;
}

vector<int> ProductArray2(vector<int> arr) {
    vector<int> left_array (arr.size());
    vector<int> right_array (arr.size());
    vector<int> prod(arr.size());

    int p = 1;
    for (int i(0); i < arr.size(); ++i) {
        left_array[i] = p;
        p *= arr[i];
    }

    p = 1;
    for (int i(arr.size() - 1); i >= 0; --i) {
        right_array[i] = p;
        p *= arr[i];
    }
    for (int i(0); i < arr.size(); ++i) {
        prod[i] = left_array[i] * right_array[i];
    }

    return prod;
}