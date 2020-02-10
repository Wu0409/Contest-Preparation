//书本215
//QUESTION：https://vjudge.net/problem/UVA-211

//注意审题：不是56张牌，是28张横放或竖着放
#include <iostream>
#include <map>
using namespace std;

int bones[7][7];
int target[7][8] = {{5,4,3,6,5,3,4,6},
                    {0,6,0,1,2,3,1,1},
                    {3,2,6,5,0,4,2,0},
                    {5,3,6,2,3,2,0,6},
                    {4,0,4,1,0,0,4,1},
                    {5,2,2,4,4,1,6,5},
                    {5,5,3,6,1,2,3,1}};
int st[7][8];
//方向
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
map <int,int> used;

void prepare(){ //给骨牌编号,初始化状态数组
    memset(st,0,sizeof(st));
    int count = 1;
    for(int i = 0;i <= 6;i++){
        for(int j = i;j <= 6;j++){
            bones[i][j] = count;
            count++;
        }
    }
}
void solution(map <int,int> ed = used,int status[][8] = st,int index = 0){
    if(index == 56){
        for(int i = 0;i <= 6;i++){
            for(int j = 0;j <= 7;j++){
                cout<<status[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    int r = index / 8;  int c = index % 8;
    if(status[r][c] != 0){
        solution(ed,status,index + 1);
        return; //这行return！！！！漏了问题很大！
    }
    for(int i = 0;i < 4;i++){
        int r_ed = r + dr[i];   int c_ed = c + dc[i];
        if(r_ed >= 0 && c_ed >= 0 && status[r_ed][c_ed] == 0){
            int a = target[r][c];   int b = target[r_ed][c_ed];
            map <int,int> temp = ed;
            if(bones[min(a,b)][max(a,b)] != 0 && !temp.count(bones[min(a,b)][max(a,b)])){
                //编号前一个大于后一个，用max，min即可
                status[r][c] = bones[min(a,b)][max(a,b)];   status[r_ed][c_ed] = bones[min(a,b)][max(a,b)];
                temp[bones[min(a,b)][max(a,b)]] = 1;
                solution(temp,status,index + 1);
                status[r][c] = 0;   status[r_ed][c_ed] = 0; //还原状态
            }
        }
    }
}

int main() {
    //样例
    prepare();
    solution();
}
