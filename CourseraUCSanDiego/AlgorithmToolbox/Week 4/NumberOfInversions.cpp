#include <iostream>
#include <vector>

using namespace std;

int merge (vector<int> &a, vector<int> &temp, int left, int mid, int right) {
    int i, j, k;
    int count = 0;
    i = left, j = mid, k = left;
    while (i <= mid - 1 && (j <= right)) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            count += (mid - i);
        }
    }
    while (i <= mid - 1) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i  = left; i <= right; ++i) {
        a[i] = temp[i];
    }
    return count;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    int mid, count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        count = get_number_of_inversions(a, b, left, mid);
        count += get_number_of_inversions(a, b, mid + 1, right);
        count += merge(a, b, left, mid + 1, right);
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
