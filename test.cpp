#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MatrixLayerInClockwise(const vector<vector<int>> &TwoDMatrix,
                            int offset, vector<int> *SpiralOrdering);
vector<int> MatrixInSpiralOrder(const vector<vector<int>> &TwoDMatrix);

int main() {
    vector<vector<int>> u = { {1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}
    };
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

vector<int> MatrixInSpiralOrder(const vector<vector<int>> &TwoDMatrix) {
    vector<int> SpiralOrdering;
    for (int offset = 0; offset < ceil(0.5 * TwoDMatrix.size()); ++offset) {
        MatrixLayerInClockwise(TwoDMatrix, offset, &SpiralOrdering);
    }
    return SpiralOrdering;
}