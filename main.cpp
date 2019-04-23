#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {}

typedef enum { RED, WHITE, BLUE} Color;

void DutchFlagPartition(vector<Color>* A_ptr, int pivot_index) {
    vector<Color> &A = *A_ptr;
    Color pivot = A[pivot_index];
    // First pass: group elements smaller than pivot.
    int smaller = 0;
    for (int i{0}; i < A.size(); ++i) {
        if (A[i] < pivot) {
            swap(A[i], A[smaller++]);
        }
    }

    // Second pass: group elements greater than pivot.
    int larger = A.size() - 1;
    for (int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i) {
        if (A[i] > pivot) {
            swap(A[i], A[larger--]);
        }
    }
}