#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
}

void InsertionSort(vector<int> &array) {
    for (int i = 1, j; i < array.size(); i++) {
        int tmp = array[i];
        for (j = i; j > 0 && tmp < array[j - 1]; j--)
            array[j] = array[j - 1];
        array[j] = tmp;
    }
}
