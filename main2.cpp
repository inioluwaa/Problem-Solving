#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

}

// P <2,0,1,3> applied to A <a,b,c,d> yield <b,c,a,d>
void ApplyPermutation(vector<int> *perm_ptr, vector<int> *A_ptr) {
    vector<int> &perm = *perm_ptr, &A = *A_ptr;
    for (int i{0}; i < A.size(); ++i) {
        // Check if the element at index i has not been moved by checking
        // if perm[i] is non-negative.
        int next = i;
        while (perm[i] >= 0) {
            swap(A[i], A[perm[next]]);
            int temp = perm[next];
            // Subtract perm.size() from an entry in perm to make it negative
            // which indicates the corresponding move has been made.
            perm[next] -= perm.size();
            next = temp;
        }
    }
}