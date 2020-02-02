//书本P191
//考察：回溯法
//QUESTION：八皇后问题

#include <iostream>
using namespace std;

int map[8][8];

bool is_ok(int r,int c){
    for(int i = 0;i < 8 && i != r;i++){ //检查一竖排
        if(map[i][c] == 1)  return false;
    }
    for(int i = -7;i <= 7;i++){ //左上到右下
        if(r+i < 0 || c+i < 0 || i == 0){
            continue;
        }
        if(map[r+i][c+i] == 1){
            return false;
        }
    }
    for(int i = -7;i <= 7;i++){ //左上到右下
        if(r+i < 0 || c-i < 0 || i == 0){
            continue;
        }
        if(map[r+i][c-i] == 1){
            return false;
        }
    }
    return true;
}

void solution(int index = 0){
    if(index == 8){
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                cout<<map[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int i = 0;i < 8;i++){
        if(is_ok(index,i)){
            map[index][i] = 1;
            solution(index + 1);
            map[index][i] = 0;  //这行非常关键！！！！注意需要复原！！！
        }
    }
    //不需要递归边界，等这一行都不满足（for循环结束）自动返回
}

int main() {
    memset(map,0,sizeof(map));
    solution();
    return 0;
}
