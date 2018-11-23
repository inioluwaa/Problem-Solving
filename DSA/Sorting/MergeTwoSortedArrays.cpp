#include <iostream>
#include <vector>

using namespace std;

void MergeTwoSortedArrays(int [], int, int [], int);
void PrintArray(int [], int);

int main() {
    int A[] = {5, 6, 7, 8};
    int B[] = {1, 2, 3, 4};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    MergeTwoSortedArrays(A, m, B, n);

    PrintArray(A, m + n);
}

void MergeTwoSortedArrays(int A[], int m, int B[], int n) {
    int a = m - 1, b = n - 1, write_idx = m + n - 1;
    while (a >= 0 && b >= 0) {
        A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
    }

    while (b >= 0) {
        A[write_idx--] = B[b--];
    }
}

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}