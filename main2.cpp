#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
bool CheckKey(unordered_set<int> u, int key);
bool AddUp(vector<int>, int);

int main() {
    vector<int> u = {10, 15, 3, 7};
    bool answer = AddUp(u, 23);
    cout << answer;
}

bool AddUp(vector<int> u, int target) {
    unordered_set<int> Checkers {};
    if (u.empty()) return false;
    for(int curr : u) {
        if(CheckKey(Checkers, target - curr)) return true;
        Checkers.insert(curr);
    }
    return false;
}

bool CheckKey(unordered_set<int> u, int key) {
    return !(u.find(key) == u.end());
}