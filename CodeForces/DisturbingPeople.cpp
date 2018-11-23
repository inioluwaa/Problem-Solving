#include <iostream>
#include <vector>
using namespace std;

int a[100];

int main() {
    int n, sum = 0;
    while (cin >> n) {
        int i;
        for (i = 0; i < n; i++)
            cin >> a[i];
        sum = 0;
        for (i = 1; i < n; i++) {
            if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
                sum++;
                a[i + 1] = 0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}