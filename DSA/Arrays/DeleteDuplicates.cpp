#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DeleteDuplicates(vector<int>*);

int main() {
}

// Return the number of valid entries after deletion.
int DeleteDuplicates(vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;
    if(A.empty()) {
        return 0;
    }
    int write_index = 1;
    for (int i{1}; i < A.size(); ++i) {
        if (A[write_index - 1] != A[i]) {
            A[write_index++] = A[i];
        }
    }
    return write_index;
}