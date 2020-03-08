//书本P262
//QUESTION：硬币问题 - DAG上的动态规划

#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 1005;//假设硬币面值最大种类数
const int INF = (1 << 30);

int coin[maxn];//各硬币面值
int d_min[maxn * maxn];//dp核心数组
int d_min1[maxn * maxn];//dp核心数组
int n;//硬币面值种类数
int S;//要得到的钱数

void init() {
    cout << "硬币面值种类总数：";
    cin >> n;
    cout << "各面值：";
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    memset(d_min, -1, sizeof(d_min));
    memset(d_min1, -1, sizeof(d_min));
    d_min[0] = 0;
    cout << "要凑得的钱数：";
    cin >> S;
    d_min1[S] = 0;
}

int dp1(int i) {
    int &ans = d_min[i];
    if (ans != -1) return ans;
    ans = INF;//改成求最大硬币数时，把此处的INF改成-INF

    for (int j = 1; j <= n; j++) {
        if (i >= coin[j]) {
            //改成求最大硬币数时，把下面的一行改成：ans=max(ans,dp(i-coin[j])+1);
            ans = min(ans, dp1(i - coin[j]) + 1);
        }
    }
    return ans;
}

int dp2(int i) {
    int &ans = d_min1[i];
    if (ans != -1) return ans;
    ans = INF;
    for (int j = 1; j <= n; j++) {
        if (S - i >= coin[j]) {
            ans = min(ans, dp2(i + coin[j]) + 1);
        }
    }
    return ans;
}

void print_dp_path(int i) {
    for (int j = 1; j <= n; j++) {
        if (i >= coin[j] && d_min[i] == d_min[i - coin[j]] + 1) {
            cout << coin[j] << " ";
            print_dp_path(i - coin[j]);
            break;
        }
    }
}


int main() {
    init();
    cout << "min求法1:(从S->0)" << dp1(S) << endl;
    cout << "min求法2:(从0->S)" << dp2(0) << endl;
    print_dp_path(S);
    cout << endl;
    return 0;
}

