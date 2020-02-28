//蓝桥杯 2017 - B 方块分割

#include <iostream>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int vis[7][7];
int ans = 0;

bool is_ok(int r, int c) {
    return (r >= 0 && r <= 6 && c >= 0 && c <= 6);
}

void dfs(int r, int c) {
    if (r == 0 || r == 6 || c == 0 || c == 6) {
        ans++;
        return;
    }
    vis[r][c] = 1;
    vis[6 - r][6 - c] = 1;
    for (int turn = 0; turn < 4; turn++) {
        int nx = r + dr[turn];
        int ny = c + dc[turn];
        if (is_ok(nx, ny) && !vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
    vis[r][c] = 0;
    vis[6 - r][6 - c] = 0;
}

int main() {
    dfs(3, 3);
    cout << ans / 4 << endl;
    return 0;
}
