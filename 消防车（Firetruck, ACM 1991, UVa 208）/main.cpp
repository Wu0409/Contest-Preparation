//书本P214
//QUESTION：https://vjudge.net/problem/UVA-208

#include <iostream>
#include <vector>

using namespace std;
int Map[20][20];    //小于20个节点
int target;
int n = 1;

void solution(int start,vector <int> ed){
    if(start == target){
        for(int i:ed){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 1;i < 20;i++){
        int u;
        if(Map[start][i] == 1){
            u = i;
        }
        else continue;
        bool ok = true;
        for(int j:ed){
            if(j == u) ok = false;
        }
        if(ok) {
            ed.push_back(u);
            solution(u, ed);
            ed.pop_back();
        }
    }
}

int main() {
    //输入目标
    cin>>target;
    memset(Map,0,sizeof(Map));
    int a,b;
    while(cin>>a>>b && (a != 0 && b != 0)){
        Map[a][b] = 1;  Map[b][a] = 1;
        n++;
    }
    vector <int> ed;
    ed.push_back(1);
    solution(1,ed);
    return 0;
}
