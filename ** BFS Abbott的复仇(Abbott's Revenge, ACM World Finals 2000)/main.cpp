//书本P165
//考察：BFS（广度优先遍历）
//QUESTION：Abbott's Revenge（类迷宫问题）

#include <iostream>
#include <queue>
using namespace std;

struct node{    //记录状态
    int r,c;    //坐标
    int dir;    //朝向
    node(int r1 = 0,int c1 = 0,int dir1 = 0):r(r1),c(c1),dir(dir1){}
};
//把方向"NESW"编号为和转弯方式"FLR"编号
const string direction = "NESW";    //0 1 2 3，顺时针
const string turns = "FLR"; //0 1 2
int dir_id(char input){
    return direction.find(input);
}
int turn_id(char input){
    return turns.find(input);
}
//行走函数
const int dr[] = {-1,0,1,0};    //不同情况对应的坐标增加值
const int dc[] = {0,1,0,-1};    //不同情况对应的坐标增加值
node walk(node& u,int turn){
    int dir = u.dir;
    if(turn == 1){
        dir = (dir + 3) % 4;
    }
    if(turn == 2){
        dir = (dir + 1) % 4;
    }
    //front方向不需要改变朝向
    return node(u.r + dr[dir],u.c + dc[dir],dir);   //返回下一个状态
}

const int maxn = 10;
int has_edge[maxn][maxn][4][3]; //记录每个节点的每个方向是否可以转向
int d[maxn][maxn][4];
node p[maxn][maxn][4];  //记录该坐标下，前一个节点，用于后续从目标节点逆序回溯到初始节点
int r0, c0, dir, r1, c1, r2, c2;    //初始节点，朝向，终点节点

bool inside(int r, int c) { //检查是否超出边界
    return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

void print_ans(node u) {
    // 从目标结点逆序追溯到初始结点
    vector<node> nodes;
    for(;;) {
        nodes.push_back(u); //放入u（终点节点）
        if(d[u.r][u.c][u.dir] == 0){    //距离为0-》到达起点，第72行设置
            break;
        }
        u = p[u.r][u.c][u.dir]; //回溯前驱节点
    }
    nodes.push_back(node(r0, c0, dir)); //结束循环后，把起点也放入，结束

    // 打印解，每行10个
    int cnt = 0;
    for(int i = nodes.size()-1; i >= 0; i--) {
        if(cnt % 10 == 0) printf(" ");
        printf(" (%d,%d)", nodes[i].r, nodes[i].c);
        if(++cnt % 10 == 0) printf("\n");
    }
    if(nodes.size() % 10 != 0) printf("\n");
}

void solve(){
    queue <node> q;
    node u(r1, c1, dir);    //起始
    d[u.r][u.c][u.dir] = 0;     //起始距离设置为0
    q.push(u);
    while(!q.empty()) {
        node u = q.front(); q.pop();
        if(u.r == r2 && u.c == c2) {    //到终点
            print_ans(u);
            return;
        }
        for(int i = 0; i < 3; i++) {    //当前位置的3个方向
            node v = walk(u, i);    //前进，获取位置状态
            if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
                //判断是否可以转向 && 是否在边界内 && 是否走过
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    cout<<"No Solution Possible!"<<endl;
}

bool read_case() {  //输入
    char s[99], s2[99];
    if(scanf("%s%d%d%s%d%d", s, &r0, &c0, s2, &r2, &c2) != 6) return false;
    printf("%s\n", s);

    dir = dir_id(s2[0]);
    r1 = r0 + dr[dir];
    c1 = c0 + dc[dir];

    memset(has_edge, 0, sizeof(has_edge));
    for(;;) {
        int r, c;
        scanf("%d", &r);
        if(r == 0) break;
        scanf("%d", &c);
        while(scanf("%s", s) == 1 && s[0] != '*') {
            for(int i = 1; i < strlen(s); i++)
                has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
        }
    }
    return true;
}

int main() {
    while(read_case()) {
        solve();
    }
    return 0;
}