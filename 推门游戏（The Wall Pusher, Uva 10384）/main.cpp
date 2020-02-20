//书本P219
//QUETION：推门游戏

#include <iostream>
#include <queue>

using namespace std;
typedef struct node{
    bool n,e,s,w;   //顺时针
    node(int n1 =0, int e1 = 0, int s1 = 0, int w1 = 0):n(n1),e(e1),s(s1),w(w1){}
};
typedef struct pos{
    int r,c;
    pos(int r1 = 0,int c1 = 0):r(r1),c(c1){}
    bool operator == (pos& other){
        return (r == other.r) && (c == other.c);
    }
};
typedef struct status{
    pos position;
    node st[4][6];
    string result;
    status(){result = "";}
    status(node other[4][6],int r1 = 0,int c1 = 0){
        result = "";
        memcpy(st,other,sizeof(st));
        position.r = r1;    position.c = c1;
    }
    status(status const &other){
        position = other.position;  memcpy(st,other.st, sizeof(st));    result = other.result;
    }
};

node Map[4][6];
queue <status> q;
status ed[1000];
int ed_c = -1;
int input[4][6] = {{10,2,10,10,2,6},
                   {3,12,11,14,9,4},
                   {13,15,3,6,15,13},
                   {14,11,12,9,14,11}};
int start_r = 3,start_c = 2;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
string direction = "NESW";

bool count(status v){
    for(int i = 0;i <= ed_c;i++){
        if((!memcmp(ed[i].st,v.st,sizeof(node[4][6]))) && (ed[i].position == v.position)){
            return true;
        }
    }
    return false;
}

bool judge(status u,int op,int opt = 0){  //判断某个位置在某个方向有没有墙
    if(opt == 0) {  //判断当前位置有没有墙
        switch (op) {
            case 0:
                return u.st[u.position.r][u.position.c].n;
            case 1:
                return u.st[u.position.r][u.position.c].e;
            case 2:
                return u.st[u.position.r][u.position.c].s;
            case 3:
                return u.st[u.position.r][u.position.c].w;
        }
    }
    else{   //判断后方位置有没有墙
        if(u.position.r+dr[op] >= 0 && u.position.c+dc[op] >= 0 && u.position.r+dr[op] <= 3 && u.position.c+dc[op] <= 5){
            switch (op) {
                case 0:
                    return u.st[u.position.r + dr[op]][u.position.c + dc[op]].n;    break;
                case 1:
                    return u.st[u.position.r + dr[op]][u.position.c + dc[op]].e;    break;
                case 2:
                    return u.st[u.position.r + dr[op]][u.position.c + dc[op]].s;    break;
                case 3:
                    return u.st[u.position.r + dr[op]][u.position.c + dc[op]].w;    break;
            }
        }
        return true;
    }
}

bool is_result(status v){
    if(v.position.r == 0){if(v.st[v.position.r][v.position.c].n == 0)  return true;}
    if(v.position.c == 5){if(v.st[v.position.r][v.position.c].e == 0)  return true;}
    if(v.position.r == 3){if(v.st[v.position.r][v.position.c].s == 0)  return true;}
    if(v.position.c == 0){if(v.st[v.position.r][v.position.c].w == 0)  return true;}
}

void solution(int r = (start_r-1),int c = (start_c-1)){
    status start(Map,r,c);
    q.push(start);
    ed_c++; memcpy(ed[ed_c].st,start.st, sizeof(start.st));
    while(!q.empty()){
        status u(q.front()); q.pop();
        if(is_result(u)){   //找到出口
            cout<<"result:"<<endl;
            cout<<u.result<<endl;   //输出运行结果
            return;
        }
        cout<<u.result<<u.position.r<<" "<<u.position.c<<endl;
        for(int op = 0;op <= 3;op++){
            if(!judge(u,op)){    //没有墙，可以直接向op方向移动
                //创建新状态
                status temp(u);  temp.result += direction[op];  temp.position.r += dr[op];  temp.position.c += dc[op];
                if(!count(temp) && temp.position.r < 4 && temp.position.c < 6 && temp.position.r >= 0 && temp.position.c >= 0) {
                    q.push(temp);
                    ed_c++; memcpy(ed[ed_c].st,temp.st, sizeof(temp.st));
                    ed[ed_c].position.r = temp.position.r;
                    ed[ed_c].position.c = temp.position.c;
                }
            }
            else{   //有墙，判断后方是否也有墙
                if(!judge(u,op,1)){ //当前位置有墙，但后方没有墙(且不是边界墙)，可以推动
                    status temp(u);  temp.result += direction[op];  temp.position.r += dr[op];  temp.position.c += dc[op];
                    switch (op){   //修改状态，原本为墙推到后面
                        case 0:
                            temp.st[u.position.r][u.position.c].n = false;
                            temp.st[u.position.r + dr[op]][u.position.c + dc[op]].n = true;
                            if(temp.st[u.position.r + dr[op] - 1])  temp.st[u.position.r + dr[op] - 1][u.position.c + dc[op]].s = true;
                            break;
                        case 1:
                            temp.st[u.position.r][u.position.c].e = false;
                            temp.st[u.position.r + dr[op]][u.position.c + dc[op]].e = true;
                            if(temp.position.c + dc[op] + 1)    temp.st[u.position.r + dr[op]][u.position.c + dc[op] + 1].w = true;
                            break;
                        case 2:
                            temp.st[u.position.r][u.position.c].s = false;
                            temp.st[u.position.r + dr[op]][u.position.c + dc[op]].s = true;
                            if(temp.position.r + dr[op] + 1)   temp.st[u.position.r + dr[op] + 1][u.position.c + dc[op]].n = true;
                            break;
                        case 3:
                            temp.st[u.position.r][u.position.c].w = false;
                            temp.st[u.position.r + dr[op]][u.position.c + dc[op]].w = true;
                            if(temp.position.r + dr[op] - 1)   temp.st[u.position.r + dr[op] - 1][u.position.c + dc[op]].e = true;
                            break;
                    }
                    if(!count(temp) && temp.position.r < 4 && temp.position.c < 6 && temp.position.r >= 0 && temp.position.c >= 0){
                        q.push(temp);
                        ed_c++; memcpy(ed[ed_c].st,temp.st, sizeof(temp.st));
                        ed[ed_c].position.r = temp.position.r;
                        ed[ed_c].position.c = temp.position.c;
                    }
                }
            }
        }
    }
}

void init(){
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 6;j++){
            int target = input[i][j];
            int w_c = 0;
            if(target % 2 == 1) w_c = 1;
            for(int n_c = 0;n_c <= 1;n_c++){
                for(int e_c = 0;e_c <= 1;e_c++){
                    for(int s_c = 0;s_c <= 1;s_c++){
                        int sum = (n_c * 2 + e_c * 4 + s_c * 8);
                        if(sum == (target - w_c)){
                            node temp(n_c,e_c,s_c,w_c);
                            Map[i][j] = temp;
                            break;
                        }
                    }
                }
            }
        }
    }
}
int main() {
    cout<<"start"<<endl;
    init();
    solution();
    return 0;
}
