//书本P217
//QUESTION：守卫棋盘 https://onlinejudge.org/external/112/11214.pdf

#include <iostream>
using namespace std;
bool input[8][8]= {{0, 0, 0, 0, 0, 0, 1, 0},
                   {0, 0, 1, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 1},
                   {0, 0, 0, 1, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {1, 0, 0, 0, 0, 0, 0, 0}};
bool vis[4][15];    //已经放置的皇后占据了哪些行（0）、列（1）、主对角线（2）、副对角线（3）
int limit = 1;
int row = 8;
int col = 8;

bool judge(){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            if(input[i][j]  && !vis[0][i] && !vis[1][j] && !vis[2][i+j] && !vis[3][i-j])    return false;
        }
    }
    return true;
}

bool solution(int depth = 0){
    if(depth == limit){
        if(judge()){
            cout<<"Ans:"<<depth<<endl;
            return true;
        }
        else return false;
    }
    for(int i = 0; i < row*col;i++){
        int r = i / col;    int c = i / col;    //行数、列数
        int t1 = vis[0][r]; int t2 = vis[1][i];  int t3 = vis[2][r+c];  int t4 = vis[3][r-c];   //用于恢复之前的状态
        vis[0][r] = vis[1][c] = vis[2][r+c] = vis[3][r-c] = true;
        if(solution(depth + 1)) return true;
        //不成功，恢复之前状态
        vis[0][r] = t1; vis[1][c] = t2; vis[2][r+c] = t3; vis[3][r-c] = t4;
    }
    return false;
}

int main() {
    cout<<"start"<<endl;
    for(int i = 1;i <= 10;i++){
        limit = i;
        if(solution())  break;
    }
    return 0;
}
