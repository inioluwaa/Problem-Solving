#include <iostream>
#include <vector>

using namespace std;
vector<int> findDiagonalOrder2(vector<vector<int>>& matrix);

int main() {
    vector<vector<int>> vect{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    // vector<vector<int>> vect{{6, 9, 7}};
    vector<int> u = findDiagonalOrder2(vect);
    for (auto i : u) {
        cout << i << " ";
    }
}

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if(matrix.empty()) return {};
    int i = 0, j = 0;
    vector<int> result;
    bool isUp = true;
    int row = matrix.size();
    int column = matrix[0].size();
    for (int k(0); k < row * column;) {
        if (isUp) {
            for (; i >= 0 && j < column; ++j, --i) {
                result.emplace_back(matrix[i][j]);
                ++k;
            }
            if (i < 0 && j < column)
                i = 0;
            if (j == column)
                i = i + 2, j--;
        }
        else {
            for (; j >= 0 && i < row; ++i, --j) {
                result.emplace_back(matrix[i][j]);
                ++k;
            }
            if (j < 0 && i < row)
                j = 0;
            if (i == row)
                j = j + 2, i--;
        }
        isUp = !isUp;
    }
    return result;
}

vector<int> findDiagonalOrder2(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return {};
    int row = matrix.size();
    int col = matrix[0].size();
    int m = 0, n = 0, dir = 1;
    for (int i(0); i < row * col; ++i) {
        result.emplace_back(matrix[m][n]);
        m -= dir;
        n += dir;
        // Out of bottom order.
        if (m >= row) {
            m--; n += 2; dir = -dir;
        }
        // Out of right order.
        if (n >= col) {
            n--, m += 2; dir = -dir;
        }
        // Out of top order.
        if (m < 0) {
            m = 0;
            dir = -dir;
        }
        // Out of left order.
        if (n < 0) {
            n = 0;
            dir = -dir;
        }
    }
    return result;
}