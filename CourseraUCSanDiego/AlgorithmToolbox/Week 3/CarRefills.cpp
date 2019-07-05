#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int num_stops = 0, journey_left = dist, last_stop = 0, i = 0;
    while (journey_left > tank && i < stops.size()) {
        while(i < stops.size() && stops[i] - last_stop < tank) {
            i++;
        }
        last_stop = stops[i - 1];
        journey_left = dist - last_stop;
        num_stops++;
    }
    return num_stops;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
