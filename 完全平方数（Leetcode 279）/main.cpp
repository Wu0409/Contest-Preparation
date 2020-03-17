//QUESTION：完全平方数 Leetcode 279

#include <iostream>
#include <vector>

using namespace std;

/*
vector<int> u;
int v[200];

int numSquares(int n) {
    int i = 2;
    memset(v, -1, sizeof(int[200]));
    u.push_back(1);
    while (i * i <= n) {
        u.push_back(i * i);
        i++;
    }
    return 1;
}

int solution(int n) {
    if (n < 0) return 99999;
    if (n == 0) return 0;
    int &ans = v[n];
    if (ans != -1) return ans;
    int i = 0;
    ans = 99999;
    while (u[i] <= n) {
        ans = min(ans, solution(n - u[i]));
        i++;
    }
    ans ++;
    return ans + 1;
}

int main() {
    numSquares(13);
    cout << solution(13) << endl;
    return 0;
}
*/

class Solution {
public:
    vector<int> u;
    int v[200];

    int solution(int n) {
        if (n < 0) return 99999;
        if (n == 0) return 0;
        int &ans = v[n];
        if (ans != -1) return ans;
        int i = 0;
        ans = 99999;
        while (u[i] <= n) {
            ans = min(ans, solution(n - u[i]));
            i++;
        }
        ans ++;
        return ans;
    }

    int numSquares(int n) {
        int i = 2;
        memset(v, -1, sizeof(int[200]));
        u.push_back(1);
        while (i * i <= n) {
            u.push_back(i * i);
            i++;
        }
        return solution(n);
    }

};

int main(){
    Solution a;
    cout<<a.numSquares(12)<<endl;
}