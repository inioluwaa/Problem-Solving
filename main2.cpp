#include <iostream>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    int n, x, y, d;

    while (testCases--) {
        cin >> n >> x >> y >> d;

        while (x % d == 0 && y % d != 0) {
            while (x < 0) {
                x -= d;
            }
        }
    }
}