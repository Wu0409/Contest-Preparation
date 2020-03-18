//QUESTION:最长上升子序列 Leetcode300

#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> input = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12}; //样例输入

//状态转移方程：dp[i] = max(dp[i], dp[j] + 1) for j in [0, i)
int lengthOfLIS(vector<int> &nums = input) {
    if(nums.size() == 0)    return 0;
    vector<int> dp( nums.size(),1);
    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

/*  我的最早方法
map <int,int>u;

int solution(vector<int>& nums,int m,int position){
    if(u.count(m)) return u[m];
    u[m] = 0;
    for(int i = position - 1;i >= 0;i--){
        if(nums[i] < m){
            u[m] = max(u[m],solution(nums,nums[i],i));
        }
    }
    u[m] ++;
    return u[m];
}

int lengthOfLIS(vector<int>& nums = input) {
    int ans = -1;
    for(int i = nums.size();i >= 0;i--){
        ans = max(ans,solution(nums,nums[i],i));
    }
    return ans;
}
*/

int main() {
    cout << lengthOfLIS() << endl;
    return 0;
}
