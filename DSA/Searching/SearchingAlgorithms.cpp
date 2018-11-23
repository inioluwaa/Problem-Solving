#include <iostream>
#include <vector>

using namespace std;

int main() {
}

// Linear Search

int LinearSearch(const vector<int> &arr, int value) {
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < arr.size() && !found) {
        if (arr[index] == value) {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

// Binary Search

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