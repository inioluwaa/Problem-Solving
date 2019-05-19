#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> GeneratePascalTriangle(int num_rows);

int main() {
    int rows = 5;
    vector<vector<int>> u = GeneratePascalTriangle(rows);
    for (const auto &i : u) {
        for (const auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    /*vector<vector<int>> u = { {1},
                              {1, 1},
                              {1, 2, 1}
    };
    vector<int> v = {1, 2, 3, 4};

    cout << u.back()[1] + u.back()[2];*/
}

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
    vector<vector<int>> pascal_triangle;
    for (int i(0); i < num_rows; ++i) {
        vector<int> curr_row;
        for (int j(0); j <= i; ++j) {
            curr_row.emplace_back(j > 0 && j < i ? pascal_triangle.back()[j - 1] + pascal_triangle.back()[j] : 1);
        }
        pascal_triangle.emplace_back(curr_row);
    }
    return pascal_triangle;
}
