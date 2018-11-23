#include <iostream>
#include <vector>

using namespace std;

int result;
int BinarySearch(const vector<int>&, int);

int main() {
    vector<int> vector1{1, 2, 3, 4, 5};

    result = BinarySearch(vector1, 3);

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