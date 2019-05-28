#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int NumberOfTimes(int N, int X);

int Segregate(vector<int> arr);
vector<int> MatrixInSpiralOrder(vector<vector<int>> TwoArr);
vector<vector<int>> MatrixSpiral(int);

int main() {
    int w = NumberOfTimes(6, 12);
    cout << w;
}

int NumberOfTimes(int N, int X) {
    int count = 0;
    for (int i(1); i <= N; ++i) {
        if (X % i == 0 && (X / i) <= N) {
            count++;
        }
    }
    return count;
}


/*int Segregate(vector<int> arr) {
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
}*/
