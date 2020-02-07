//书本P207
//考察：迭代加深搜索
//QUESTION：埃及分数问题

#include <iostream>

using namespace std;

const int maxn = 100;
int a,b;
int max_depth;  //深度
long long v[maxn], ans[maxn];   //记录分母

int get_first(int a, int b) {
    return b/a+1;
}

long long gcd(long long a, long long b) {   //化简分母！！
    return b == 0 ? a : gcd(b, a%b);
}

bool better(int depth){
    for(int i = depth; i >= 0; i--) if(v[i] != ans[i]) {
            return ans[i] == -1 || v[i] < ans[i];
        }
    return false;
}

bool dfs(int depth,int from,int a,int b){   //参数分别为 当前深度 开始的分母 所求的分子 所求的分母
    if(depth == max_depth){
        if(b % a){  //到达最大深度，若 b%a != 0,则说明还不是埃及分数，还需要分解
            return false;
        }
        else{   //是埃及分数
            v[depth] = b/a; //记录当前深度的结果
            if(better(depth))   memcpy(ans, v, sizeof(long long) * (depth+1));    //比原先答案更好，复制给ans数组，记录
            return true;
        }
    }
    int start = max(from,get_first(a,b));    //????
    bool ok = false;
    for(int i = start;;i++){
        // 剪枝：如果剩下的maxd+1-d个分数全部都是1/i，加起来仍然不超过a/b，则无解（不需要再向下递归，没有意义，必不可能得到a/b）
        if(b * (max_depth + 1 - depth) <= i * a) break;
        v[depth] = i;
        // 计算a/b - 1/i，设结果为a2/b2
        long long b2 = b * i;   //通分形式
        long long a2 = a*i - b; //通分形式
        long long g = gcd(a2, b2); //求出最大公约数
        if(dfs(depth + 1,i+1,a2/g,b2/g)) ok = true;
    }
    return ok;
}

int main() {
    bool ok = false;
    cin >> a >> b;
    for (max_depth = 1; max_depth <= 100; max_depth++) {
        memset(v, -1, sizeof(v));
        memset(ans, -1, sizeof(ans));    //初始化记录答案的数组，初始值全部设置为-1，在比较结果时候需要使用
        if (dfs(0, get_first(a, b), a, b)) {
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << a << "/" << b << " = ";
        int i;
        for (i = 0; i <= maxn && ans[i + 1] != -1; i++) {
            cout << 1 << "/" << ans[i] << " + ";
        }
        cout << 1 << "/" << ans[i];
        cout << endl;
    } else cout << "No solution!" << endl;
    return 0;
}