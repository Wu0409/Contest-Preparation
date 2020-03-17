//QUESTION:打家劫舍2 Leetcode 213

#include <iostream>
#include <vector>

using namespace std;

int u[4];
vector<int> input = {1};

int solution(vector<int> &nums = input, int m = 0) {
    if (m < 0) return 0;
    int &ans = u[m];
    if (ans != -1) return ans;
    ans = max(solution(nums, m - 1), solution(nums, m - 2) + nums[m]);
    return ans;
}

int rob(vector<int> &nums = input) {
    memset(u, -1, sizeof(int[4]));
    vector<int> a1(nums.begin() + 1, nums.end());
    vector<int> b1(nums.begin(), nums.end() - 1);

    int a = solution(a1, a1.size() - 1);
    memset(u, -1, sizeof(int[4]));
    int b = solution(b1, b1.size() - 1);
    return max(a, b);
}


int main() {
    cout << solution() << endl;
    return 0;
}
