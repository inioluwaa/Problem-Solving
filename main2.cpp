#include <iostream>
#include <vector>

using namespace std;

unsigned CountInRange (vector<int> &a, int num, int left, int right) {
    unsigned int count = 0;
    for (int i(left); i <= right; ++i) {
        if (a[i] == num)
            count++;
    }
    return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
    if (left > right) return -1;
    if (left == right) return a[left];
    int middle = left + (right - left) / 2;
    int left_side = get_majority_element(a, left, middle);
    int right_side = get_majority_element(a, middle + 1, right);

    if (left_side == right_side) return left_side;

    int left_count = CountInRange(a, left_side, left, right);
    int right_count = CountInRange(a, right_side, left, right);

    if (left_count > a.size()/2) return left_side;
    else if (right_count > a.size()/2) return right_side;
    else return 0;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
