//书本P217
//QUESTION：守卫棋盘 https://onlinejudge.org/external/112/11214.pdf

#include <iostream>
#include <vector>
using namespace std;
typedef struct p{
    int r,c;
    p(int r1,int c1):r(r1),c(c1){}
};
bool input[8][8]= {{0, 0, 0, 0, 0, 0, 1, 0},
                   {0, 0, 1, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 1},
                   {0, 0, 0, 1, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {1, 0, 0, 0, 0, 0, 0, 0}};
vector <p> target;
vector <int> ans;

void init(){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            if(input[i][j]){
                p temp(i,j);    target.push_back(temp);
            }
        }
    }
}

bool is_boundry(int r,int c){
    return (r >= 0 && c >= 0 && r < 8 && c < 8);
}
void solution(int turn = 0,int index = 0,bool status[8][8] = input){
    if(index == target.size()){
        ans.push_back(turn);
        return;
    }
    int r = target[index].r;  int c = target[index].c;
    if(status[r][c] == 0){
        solution(turn + 1,index + 1,status);
        return;
    }
    for(int i = -7;i <= 7;i++){
        if(!is_boundry(r+i,c+i)) continue;
        int r_ed = r + i;   int c_ed = c + i;
        bool temp_status[8][8]; memcpy(temp_status,status,sizeof(temp_status));
        for(int a = -7;a <= 7;a++){
            if(!is_boundry(r_ed + a,c_ed + a)) continue;
            if(temp_status[r_ed + a][c_ed + a]) temp_status[r_ed + a][c_ed + a] = false;
        }
        for(int b = -7;b <= 7;b++){
            if(!is_boundry(r_ed + b,c_ed - b)) continue;
            if(temp_status[r_ed + b][c_ed - b]) temp_status[r_ed + b][c_ed - b] = false;
        }
        solution(turn + 1,index + 1,temp_status);
    }
    for(int i = -7;i <= 7;i++){
        if(!is_boundry(r+i,c-i)) continue;
        int r_ed = r + i;   int c_ed = c - i;
        bool temp_status[8][8]; memcpy(temp_status,status,sizeof(temp_status));
        for(int a = -7;a <= 7;a++){
            if(!is_boundry(r_ed + a,c_ed + a)) continue;
            if(temp_status[r_ed + a][c_ed + a]) temp_status[r_ed + a][c_ed + a] = false;
        }
        for(int b = -7;b <= 7;b++){
            if(!is_boundry(r_ed + b,c_ed - b)) continue;
            if(temp_status[r_ed + b][c_ed - b]) temp_status[r_ed + b][c_ed - b] = false;
        }
        solution(turn + 1,index + 1,temp_status);
    }
}

int main() {
    init(); solution();
    sort(ans.begin(),ans.end());
    cout<<"Case:"<<*(ans.end() - 1)<<endl;
    return 0;
}
