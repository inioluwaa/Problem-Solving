#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int BuyAndSellStocksOnce(const vector<int> &);
double BuyAndSellStocksOnce(const vector<double> &);

int main() {
    vector<int> vect{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    int result = BuyAndSellStocksOnce(vect);
    cout << result;
    /*for (auto i : result) {
        cout << i << " ";
    }*/
}

int BuyAndSellStocksOnce(const vector<int> &prices) {
    int maximum = 0, maxidad = 0;
    vector<int> result;
    for (int i(0); i < prices.size() - 1; ++i) {
        for (int j = i + 1; j < prices.size(); ++j) {
            maximum = max(maximum, prices[j]);
        }
        result.emplace_back(maximum - prices[i]);
        maximum = 0;
    }
    for (int i : result) {
        maxidad = max(maxidad, i);
    }
    return maxidad;
}

double BuyAndSellStocksOnce(const vector<double> &prices) {
    double min_price_so_far = numeric_limits<double>::max(), max_profit = 0;
    for (const double &price : prices) {
        double max_profit_sell_today = price - min_price_so_far;
        max_profit = max(max_profit, max_profit_sell_today);
        min_price_so_far = min(min_price_so_far, price);
    }
    return max_profit;
}