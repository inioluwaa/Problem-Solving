#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
}

void SelectionSort(vector<int> &array) {
    int minIndex, minValue;

    for (int start = 0; start < (array.size() - 1); start++) {
        minIndex = start;
        minValue = array[start];

        for (int index = start + 1; index < array.size(); index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}
