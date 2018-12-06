#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long t, n, x, y, d;
    auto ans = static_cast<long long int>(2e9);
    cin >> t;

    while (t--) {
        cin >> n >> x >> y >> d;

        if (abs(x - y) % d == 0)
            ans = abs(x - y) / d;
        if ((y - 1) % d == 0)
            ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
        if ((n - y) % d == 0)
            ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
        if (ans == 2e9)
            ans = -1;
        cout << ans << endl;
    }
}