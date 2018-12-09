// Problem 581A - CodeForces - Vasya the Hipster.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    auto ans = static_cast<unsigned int>(abs(a - b));
    cout << min(a, b) << " " << ans/2;
}