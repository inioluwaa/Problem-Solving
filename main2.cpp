#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void Segregate(vector<int> arr);

int main() {
    vector<int> u = {1, 2, -1 , 2, 0, -1};
    Segregate(u);
    for (auto i : u)
        cout << i << " ";
}

void Segregate(vector<int> arr) {
    int j = 0;
    for (int i(0); i < arr.size(); ++i) {
        if (arr[i] <= 0) {
            swap(arr[i], arr[j++]);
        }
    }
    // return j;
}

/*
int FindMissingPositive(vector<int> arr) {
    for (int i(0); i < arr.size(); ++i) {

    }
}*/
