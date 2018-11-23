#include <iostream>
#include <vector>

using namespace std;

int result, s;
int BinarySearch(const vector<int>&, int);

int main() {
    const int SIZE = 5;
    vector<int> vector1(SIZE);

    for (auto &i : vector1) {
        cin >> i;
    }
    cout << "Enter a value to search for" << endl;
    cin >> s;


    result = BinarySearch(vector1, s);

    if (result == -1)
        cout << "Element is not present in the array" << endl;
    else
        cout << "Element is present at " << result << endl;

}

int BinarySearch(const vector<int> &arr, int value) {
    int left = 0, right = arr.size() - 1, middle, position = -1;
    bool found = false;

    while (!found && left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == value) {
            found = true;
            position = middle;
        }
        else if (arr[middle] > value)
            right = middle - 1;

        else // (arr[middle] < value)
            left = middle + 1;
    }
    return position;
}