//QUESTION:整数拆分 Leetcode343
//备注：你可以假设 n 不小于 2 且不大于 58

#include <iostream>
#include <vector>
using namespace std;
int u[58];

int solution(int n) {
    int &ans = u[n];
    if (ans != -1) return ans;
    int turn = n / 2;
    for(int i = 1;i <= turn;i++){
        vector<int>re;
        re.push_back(solution(i) * solution(n - i));
        re.push_back(solution(i) * (n - i));
        re.push_back(i * solution(n - i));
        re.push_back((i)*(n-i));
        sort(re.begin(),re.end());
        ans = *(re.end()-1);
    }
    return ans;
}

int main() {
    memset(u, -1, sizeof(int[58]));
    u[1] = 1;   u[2] = 1;
    cout<<solution(10)<<endl;
    return 0;
}
