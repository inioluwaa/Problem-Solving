#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Segregate(vector<int> arr);
vector<int> MatrixInSpiralOrder(vector<vector<int>> TwoArr);

int main() {
    // N X N
    vector<vector<int>> u = { {1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}
    };
    // N X M
    vector<vector<int>> v = { {1, 2, 3, 4, 5},
                              {6, 7, 8, 9, 10},
                              {11, 12, 13, 14, 15},
                              {16, 17, 18, 19, 20}
    };
    vector<int> w = MatrixInSpiralOrder(u);
    for (auto i : w) {
        cout << i << " ";
    }
}




/*
int Segregate(vector<int> arr) {
    vector<int> &result = arr;
    int j = 0;
    for (int i(0); i < result.size(); ++i) {
        if (result[i] > 0) {
            swap(result[i], result[j++]);
        }
    }
    return j;
}

int FindMissingPositive(vector<int> arr) {
    int end = Segregate(arr);
    for (int i(0); i < end; ++i) {
        int x = abs(arr[i]) - 1;
        if (x < end && x > 0) {
            arr[x] = -arr[x];
        }
    }
    for (int i(0); i < end)
}
*/
