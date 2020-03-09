//QUESTION:Leetcode 669 Coin Change

#include <iostream>

using namespace std;
const int INF = (1 << 30);
int u[28];  //记录
int coin[] = {2, 5, 7};

void init() {
    memset(u, -1, sizeof(int[28]));
    u[0] = 0;
}

int solution(int i) {
    if (i < 0) return INF;
    if (i == 0) return 0;
    if (u[i] != -1) return u[i];
    u[i] = INF;
    for (int j = 0; j <= 2; j++) {
        u[i] = min(solution(i - coin[j]) + 1, u[i]);
    }
    return u[i];
}

bool display(int i, int ans) {
    if (i == 0) return true;
    for (int j = 0; j <= 2; j++) {
        if (u[i - coin[j]] == (ans - 1)) {
            cout << coin[j] << " ";
            if(display(i - coin[j], ans - 1))   return true;
        }
    }
}

int main() {
    init();
    int ans = solution(27);
    cout<<ans<<endl;
    display(27, ans);
}
