#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
bool CanReachEnd(const vector<int> &);


int main() {
    vector<int> v {3, 3, 1, 0, 2, 0, 1};
    bool b = CanReachEnd(v);
    cout << b;
}


bool CanReachEnd(const vector<int> &max_advance_steps) {
    int furthest_reached_so_far = 0, last_index = max_advance_steps.size() - 1;
    for(int i{0}; i <= furthest_reached_so_far && furthest_reached_so_far < last_index; ++i) {
        furthest_reached_so_far = max(furthest_reached_so_far, max_advance_steps[i] + i);
    }
    bool result = furthest_reached_so_far >= last_index;
    return result;

    // return furthest_reached_so_far >= last_index;
}
