/*This problem was asked by Microsoft.

Given a 2D matrix of characters and a target word, write a function
that returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
['O', 'B', 'Q', 'P'],
['A', 'N', 'O', 'B'],
['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true, since it's the leftmost column.
Similarly, given the target word 'MASS',you should return true, since it's the last row.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool CheckRight(const vector<vector<char>> &CheckerMatrix, int i, int j, const string& target);
bool WordPuzzle(const vector<vector<char>> &CheckerMatrix, const string& target);
bool CheckDown(const vector<vector<char>> &CheckerMatrix, int i, int j, const string &target);

int main() {
    vector<vector<char>> Checker = {
            {'F', 'A', 'C', 'I'},
            {'O', 'B', 'Q', 'P'},
            {'A', 'N', 'O', 'B'},
            {'M', 'A', 'S', 'S'}
    };
    bool answer = WordPuzzle(Checker, "FOAM");
    cout << answer;
}

bool WordPuzzle(const vector<vector<char>> &CheckerMatrix, const string& target) {
    int row_size = CheckerMatrix.size();
    int col_size = CheckerMatrix[0].size();

    for (int i(0); i < row_size; ++i) {
        for (int j(0); j < col_size ; ++j) {
            if (target.front() == CheckerMatrix[i][j]) {
                if (CheckRight(CheckerMatrix, i, j, target) || CheckDown(CheckerMatrix, i, j, target))
                    return true;
            }
        }
    }
    return false;
}

bool CheckRight(const vector<vector<char>> &CheckerMatrix, int i, int j, const string &target) {
    int k = 0;
    while (j < CheckerMatrix[i].size() && target[k] == CheckerMatrix[i][j]) {
        k++;
        j++;
    }
    return k == target.size();
}

bool CheckDown(const vector<vector<char>> &CheckerMatrix, int i, int j, const string &target) {
    int k = 0;
    while (i < CheckerMatrix.size() && target[k] == CheckerMatrix[i][j]) {
        k++;
        i++;
    }
    return k == target.size();
}