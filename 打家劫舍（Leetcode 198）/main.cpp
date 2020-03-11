//QUESTION：打家劫舍

#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    // 子问题：
    // f(k) = 偷 [0..k) 房间中的最大金额

    // f(0) = 0
    // f(1) = nums[0]
    // f(k) = max{ rob(k-1), nums[k-1] + rob(k-2) }

    int N = nums.size();
    vector<int> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int k = 2; k <= N; k++) {
        dp[k] = max(dp[k-1], nums[k-1] + dp[k-2]);
    }
    return dp[N];
}

int main() {
    vector <int> nums = {1,2,3,1};
    cout<<rob(nums)<<endl;
    return 0;
}
