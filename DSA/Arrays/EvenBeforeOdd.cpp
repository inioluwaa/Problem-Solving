#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
void EvenOdd(vector<int> *);

int main(){
}

void EvenOdd(vector<int> *A_ptr) {
    vector<int> A = *A_ptr;
    int next_even = 0, next_odd = A.size() - 1;
    while (next_even < next_odd) {
        if (A[next_even] % 2 == 0) {
            next_even++;
        }
        else {
            swap(A[next_even], A[next_odd--]);
        }
    }
}