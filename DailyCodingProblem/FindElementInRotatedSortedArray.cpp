// DCP #58
/*
A sorted array of integers was rotated an unknown number of times.
Given such an array, find the index of the element in the array in faster
than linear time. If the element doesn't exist in the array, return null.

for example, given the array [13, 18, 25, 2, 8, 10] and the target element 8,
return 4 (the index of n in the array).

You can assume all the integers in the array are unique
*/

#include <iostream>
#include <vector>

using namespace std;

int FindPivotIndex(const vector<int> &arr) {
    if (arr[arr.size() - 1] > arr[0]) return -1;
    int pivot = 0;
    for (int i(1); i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            pivot = i - 1;
            break;
        }
    }
    return pivot;
}

int BinarySearch(const vector<int> &arr, int low, int high, int target) {
    if (high < low) return -1;
    int mid = (low + high) / 2;
    if (target == arr[mid])
        return mid;
    if (target >= arr[mid])
        return BinarySearch(arr, mid + 1, high, target);
    else
        return BinarySearch(arr, low, mid - 1, target);
}

int FindElementInRotatedSortedArray(const vector<int> &arr, int target) {
    int pivot = FindPivotIndex(arr);
    if (pivot == -1) {
        return BinarySearch(arr, 0, arr.size() - 1, target);
    }
    if (arr[pivot] == target) return pivot;
    else if (arr[0] <= target) return BinarySearch(arr, 0, pivot - 1, target);
    else {
        return BinarySearch(arr, pivot + 1, arr.size() - 1, target);
    }
}

int main() {
    vector<int> arr = {13, 18, 25, 2, 8, 10};
    cout << FindElementInRotatedSortedArray(arr, 3);
}