//QUESTION:最大子序和 Leetcode 53

#include <iostream>
#include <vector>

using namespace std;

vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

int maxSubArray(vector<int> &nums = input) {
    int dp = nums[0];
    int result = -(1 << 30);
    for (int i = 1; i < nums.size(); i++) {
        dp = max(nums[i], dp + nums[i]);
        result = max(result, dp);
    }
    return result;
}

int main() {
    cout << maxSubArray() << endl;
    return 0;
}
