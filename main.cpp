//UNSORTED
// Given a list of n - 1 integers and these integers are in the range of
// 1 to n. There are no duplicates in the list. One of the integers is missing
// in the list. Write an efficient code to find the missing integer.
// Example:
// Input : arr[] = [1, 2, 4, 6, 3, 7, 8]
// Output : 5

#include <iostream>
#include <vector>

using namespace std;
int GetMissingNumber(vector<int>);

int main() {
    vector<int> u = {1, 2, 4, 6, 3, 7, 8};
    int v = GetMissingNumber(u);
    cout << v;
}

int GetMissingNumber(vector<int> arr) {
    int n = arr.size();
    int total;
    total = (n + 1) * (n + 2) / 2;
    for (int i : arr) {
        total -= i;
    }
    return total;
}

