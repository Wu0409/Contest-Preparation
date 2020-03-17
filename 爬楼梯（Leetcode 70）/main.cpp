//QUESTION:爬楼梯

#include <iostream>
using namespace std;

int u[999];

int climbStairs(int n) {
    if(n == 0)  return 1;
    int &ans = u[n];
    if(ans != -1)   return ans;
    ans = climbStairs(n - 2) + climbStairs(n - 1);
    return ans;
}

int main() {
    memset(u,-1,sizeof(int[999]));
    cout<<climbStairs(3)<<endl;
    return 0;
}
