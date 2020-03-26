#include <iostream>
#include <queue>
using namespace std;
typedef struct status{
    int r;
    int c;
    status(int r1,int c1):r(r1),c(c1){}
};

char map[7][7] = {{'.','.','.','.','.','.','.'},
                  {'.','#','#','.','.','.','.'},
                  {'.','#','#','.','.','.','.'},
                  {'.','.','.','.','#','#','.'},
                  {'.','.','#','#','#','#','.'},
                  {'.','.','.','#','#','#','.'},
                  {'.','.','.','.','.','.','.'}};
bool vis[7][7];
queue <status> q;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int ans;

void bfs(int r,int c){
    int num = 0,ed = 0;
    if(vis[r][c])  return;
    status t(r,c);
    q.push(t);
    vis[r][c] = true;
    num ++;
    while(!q.empty()) {
        status u(q.front().r,q.front().c);  q.pop();
        for (int i = 0; i < 4; i++){
            if(map[u.r + dr[i]][u.c + dc[i]] == '.'){
                ed += 1;
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            int v_r = u.r + dr[i];
            int v_c = u.c + dc[i];
            if(v_c >= 0 && v_r >= 0 && v_r < 7 && v_c < 7 && map[v_r][v_c] == '#' && !vis[v_r][v_c]){
                status v(v_r,v_c);
                vis[v_r][v_c] = true;
                num++;
                q.push(v);
            }
        }
    }
    if(num == ed)   ans++;
}

int main() {
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            if(map[i][j] == '#')  bfs(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
