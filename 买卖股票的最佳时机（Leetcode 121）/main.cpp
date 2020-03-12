//买卖股票的最佳时机 Leetcode 121
//符合Leetcode判题条件使用vectro

#include <iostream>
#include <vector>

using namespace std;
vector<int> prices = {7, 1, 5, 3, 6, 4};

int maxProfit(vector<int> &prices) {
    int min_price = prices[0];
    int n = prices.size();
    vector<int> dp (n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        min_price = min(min_price, prices[i]);
        dp[i] = max(dp[i - 1], prices[i] - min_price);
    }
    return dp[n - 1];
}

int main() {
    cout << maxProfit(prices) << endl;
    return 0;
}
