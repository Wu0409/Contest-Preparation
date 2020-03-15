//QUESTION:不同路径

#include <iostream>
using namespace std;

/*
int u[100][100];
int m = 7,n = 3;
int solution(int m = 0, int n = 0) {
    if(m >= 7 || n >= 3)    return 0;
    if(m == 6 && n == 3){
        return 1;
    }
    int &ans = u[m][n];
    if(ans != -1)   return ans;
    ans = 0;
    ans += solution(m+1,n) + solution(m,n+1);
    return ans;
}
 */
class Solution {
public:
    int target_r,target_c;
    int u[100][100];
    int solution(int m = 0, int n = 0) {
        if(m >= target_r || n >= target_c)    return 0;
        if(m == (target_r - 1) && (n == target_c - 1))  return 1;
        int &ans = u[m][n];
        if(ans != -1)   return ans;
        ans = 0;
        ans += solution(m+1,n) + solution(m,n+1);
        return ans;
    }

    int uniquePaths(int m, int n) {
        memset(u,-1, sizeof(int[100][100]));
        target_r = m;   target_c = n;
        return solution();
    }
};

int main() {
    /*
    memset(u,-1, sizeof(int[100][100]));
    cout<<solution()<<endl;
     */
    Solution a;
    cout<<a.uniquePaths(3,7)<<endl;
    return 0;
}
