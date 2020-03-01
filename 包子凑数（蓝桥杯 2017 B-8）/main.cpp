//蓝桥杯 2017 B-8 包子凑数

#include <iostream>

using namespace std;

bool u[10000];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int num, g = 0, ans = 0;
    memset(u, false, sizeof(bool[10000]));
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        int in;
        scanf("%d", &in);
        g = gcd(in, g);
        u[in] = true;
        for (int j = 1; j < 10000; j++) {
            if (u[j] && u[j] + in < 10000) {
                u[j + in] = true;
            }
        }
    }
    if (g != 1) {
        cout << "INF" << endl;
    } else {
        for (int i = 1; i < 10000; i++) {
            if (!u[i]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
