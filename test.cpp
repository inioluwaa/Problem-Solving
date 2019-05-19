#include <iostream>
#include <string>
#include <vector>

using namespace std;

string WordPuzzle(const vector<vector<char>> &CheckerMatrix, const string& target);

int main() {
    vector<vector<char>> Checker = {
            {'F', 'A', 'C', 'T'},
            {'O', 'B', 'Q', 'S'},
            {'A', 'N', 'Z', 'D'},
            {'M', 'D', 'P', 'E'}
    };
    string answer = WordPuzzle(Checker, "BQS");
    cout << answer;
}

string WordPuzzle(const vector<vector<char>> &CheckerMatrix, const string& target) {
    string worddown, wordright;
    int row_size = CheckerMatrix.size();
    int col_size = CheckerMatrix[0].size();
    for (int i(0); i < row_size; ++i) {
        for (int j(0); j < col_size; ++j) {
            if (CheckerMatrix[i][j] == target[0]) {
                worddown.push_back(target[0]);
                wordright.push_back(target[0]);
                for (int k(i + 1); k <= target.size() - 1; ++k) {
                    worddown.push_back(CheckerMatrix[k][j]);
                }
                for (int l(j + 1); l <= target.size() - 1 && j != target.size(); ++l) {
                    wordright.push_back(CheckerMatrix[i][l]);
                }
            }
        }
        /*if (worddown == target || wordright == target) {
            return worddown;
        }*/
    }
    return wordright;
}