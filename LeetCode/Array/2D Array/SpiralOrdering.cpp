#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MatrixLayerInClockwise(const vector<vector<int>> &TwoDMatrix,
                            int offset, vector<int> *SpiralOrdering);
vector<int> MatrixInSpiralOrder(const vector<vector<int>> &TwoDMatrix);

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
    vector<int> w = MatrixInSpiralOrder(v);
    for (auto i : w) {
        cout << i << " ";
    }
}

void MatrixLayerInClockwise(const vector<vector<int>> &TwoDMatrix,
                            int offset, vector<int> *SpiralOrdering) {
    int row_size = TwoDMatrix.size();
    int col_size = TwoDMatrix[0].size();
    for (int j = offset; j < col_size - offset - 1; ++j) {
        SpiralOrdering->emplace_back(TwoDMatrix[offset][j]);
    }
    for (int i = offset; i < row_size - offset - 1; ++i) {
        SpiralOrdering->emplace_back(TwoDMatrix[i][col_size - offset - 1]);
    }
    for (int j = col_size - offset - 1; j > offset; --j) {
        SpiralOrdering->emplace_back(TwoDMatrix[row_size - offset - 1][j]);
    }
    for (int i = row_size - offset - 1; i > offset; --i) {
        SpiralOrdering->emplace_back(TwoDMatrix[i][offset]);
    }

    if (offset == TwoDMatrix.size() - offset - 1) {
        // Square Matrix has odd dimension, and we are at the middle of the square matrix.
        SpiralOrdering->emplace_back(TwoDMatrix[offset][offset]);
    }
}

// Solution 1
vector<int> MatrixInSpiralOrder(const vector<vector<int>> &TwoDMatrix) {
    vector<int> SpiralOrdering;
    for (int offset = 0; offset < ceil(0.5 * TwoDMatrix.size()); ++offset) {
        MatrixLayerInClockwise(TwoDMatrix, offset, &SpiralOrdering);
    }
    return SpiralOrdering;
}

// Solution 2
vector<int> MatrixInSpiralOrder(const vector<vector<int>> &TwoDMatrix) {
    vector<int> SpiralOrdering;
    for (int offset = 0; offset < ceil(0.5 * TwoDMatrix.size()); ++offset) {
        int row_size = TwoDMatrix.size();
        int col_size = TwoDMatrix[0].size();
        for (int j = offset; j < col_size - offset - 1; ++j) {
            SpiralOrdering.emplace_back(TwoDMatrix[offset][j]);
        }
        for (int i = offset; i < row_size - offset - 1; ++i) {
            SpiralOrdering.emplace_back(TwoDMatrix[i][col_size - offset - 1]);
        }
        for (int j = col_size - offset - 1; j > offset; --j) {
            SpiralOrdering.emplace_back(TwoDMatrix[row_size - offset - 1][j]);
        }
        for (int i = row_size - offset - 1; i > offset; --i) {
            SpiralOrdering.emplace_back(TwoDMatrix[i][offset]);
        }

        if ((offset == TwoDMatrix.size() - offset - 1) && row_size == col_size) {
            // Square Matrix has odd dimension, and we are at the middle of the square matrix.
            SpiralOrdering.emplace_back(TwoDMatrix[offset][offset]);
        }
    }
    return SpiralOrdering;
}

// Solution 3
// O(n)
vector<int> MatrixInSpiralOrder(vector<vector<int>> TwoArr) {
    vector<int> spiral_ordering;
    if (TwoArr.empty()) return spiral_ordering;
    int row_size = TwoArr.size();
    int col_size = TwoArr[0].size();

    vector<int> dir_row = {0, 1, 0, -1};
    vector<int> dir_col = {1, 0, -1, 0};

    int r = 0, c = 0, dir = 0;
    for (int i(0); i < row_size * col_size; ++i) {
        spiral_ordering.emplace_back(TwoArr[r][c]);
        TwoArr[r][c] = 0;
        int next_r = r + dir_row[dir];
        int next_c = c + dir_col[dir];
        if (next_r < 0 || next_r >= row_size || next_c < 0 ||
            next_c >= col_size || TwoArr[next_r][next_c] == 0) {
            dir = (dir + 1) % 4;
            next_r = r + dir_row[dir];
            next_c = c + dir_col[dir];
        }
        r = next_r, c = next_c;
    }
    return spiral_ordering;
}
