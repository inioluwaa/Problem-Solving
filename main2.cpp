#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
void ApplyPermutation(vector<int> *, vector<int> *);
void ApplyPermutation(const vector<int> &, vector<int> *);
void CyclicPermutation(int start, const vector<int> &perm, vector<int> *A_ptr);

int main() {
    vector<int> u = {2, 0, 1, 3};
    vector<int> v = {1, 2, 3, 4};
    ApplyPermutation(u, &v);
    for (auto i : v)
        cout << i << " ";
}

// Solution 2.
// perm<2,0,1,3> <----> A<a,b,c,d>  -----> <b,c,a,d>
void ApplyPermutation(const vector<int> &perm, vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;
    for (int i{0}; i < A.size(); ++i) {
        // Traverse the cycle to see if i is the minimum element.
        bool is_min = true;
        int j = perm[i];        //
        while (j != i) {
            if (j < i) {
                is_min = false;
                break;
            }
            j = perm[j];
        }
        if (is_min) {
            CyclicPermutation(i, perm, &A);
        }
    }
}

void CyclicPermutation(int start, const vector<int> &perm, vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;
    int i = start;
    int temp = A[start];
    do {
        int next_i = perm[i];
        int next_temp = A[next_i];
        A[next_i] = temp;
        i = next_i, temp = next_temp;
    } while (i != start);
}

//////////////////////////////////////////////////////////////////////////////////////


// Solution 1 ---> Not working yet
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
    // Restore perm.
    for_each(begin(perm), end(perm), [&perm](int &x) { x += perm.size(); });
}