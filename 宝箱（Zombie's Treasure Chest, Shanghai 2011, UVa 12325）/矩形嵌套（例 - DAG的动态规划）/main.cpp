//书本P262
//QUESTION:矩形嵌套 - DAG动态规划

#include <iostream>

using namespace std;

int num = 0;
int rect[1000][2];
bool g[1000][1000];
int d[1000];

bool is_ok(int a, int b, int c, int d) {
    return (a < c && b < d) || (b < c && a < d);
}

int dp(int i) {
    int &ans = d[i];
    if (ans > 0) return ans;
    ans = 1;
    for (int j = 1; j <= num; j++) {
        if(g[i][j]) ans = max(ans,dp(j) + 1);
    }
    return ans;
}

int main() {
    memset(d, -1, sizeof(int[1000]));
    cin >> num;
    for (int i = 1; i <= num; i++) {
        cin >> rect[i][0] >> rect[i][1];
    }
    for (int i = 1; i <= num; i++) {
        for (int j = i + 1; j <= num; j++) {
            if (is_ok(rect[i][0], rect[i][1], rect[j][0], rect[j][1])) g[i][j] = true;
        }
    }
    /*
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
     */
    cout<<dp(2)<<endl;
}