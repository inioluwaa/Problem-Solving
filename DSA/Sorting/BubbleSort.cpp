#include <iostream>
#include <vector>

using namespace std;

int temp;
void BubbleSort(vector<int> &);
void PrintArray(vector<int> &);

int main() {

    vector<int> vector1{12, 10, 4, 5 ,6, 2};

    BubbleSort(vector1);
    PrintArray(vector1);
}

void swap(int &a, int &b) {
    temp = a;
    a = b;
    b = temp;
}
void BubbleSort(vector<int> &array) {
    int i, j, n = array.size();
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void PrintArray(vector<int> &arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}