#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> GenerateMatrix2(int n);

int main() {
    int n = 4;
    vector<vector<int>> GeneratedMat = GenerateMatrix2(n);
    for (const auto &i : GeneratedMat) {
        for (const auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> GenerateMatrix(int n) {
    vector<vector<int>> Generated(n, vector<int> (n, 0));
    int count = 1, row = 0, column = 0, dir = 0;
    while (count <= n * n) {
        Generated[row][column] = count++;
        if (dir == 0) {
            column++;
            if (column == n || Generated[row][column] != 0)
                dir = 1, column--, row++;
        }
        else if (dir == 1) {
            row++;
            if(row == n || Generated[row][column] != 0)
                dir = 2, row--, column--;
        }
        else if (dir == 2) {
            column--;
            if (column < 0 || Generated[row][column] != 0)
                dir = 3, column++, row--;
        }
        else if (dir == 3) {
            row--;
            if (row < 0 || Generated[row][column] != 0)
                dir = 0, column++, row++;
        }
    }
    return Generated;
}

vector<vector<int>> GenerateMatrix2(int n) {
    vector<vector<int>> generated(n);
    for (int i = 0; i < n; ++i)
        generated[i].resize(n);

    int top = 0, bottom = n - 1, left = 0, right = n - 1, value = 1;
    while (value <= n * n) {
        for (int i = left; i <= right; ++i) {
            generated[top][i] = value++;
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            generated[i][right] = value++;
        }
        right--;
        for (int i = right; i >= left; --i) {
            generated[bottom][i] = value++;
        }
        bottom--;
        for (int i = bottom; i >= top; --i) {
            generated[i][left] = value++;
        }
        left++;
    }
    return generated;
}