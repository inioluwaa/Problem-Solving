/*This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?*/

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