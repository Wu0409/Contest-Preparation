//九宫重排 蓝桥杯
//https://www.dotcpp.com/oj/problem1426.html

#include<iostream>
#include <queue>
#include <map>
using namespace std;
string input,output;
queue <string> q;
map <string,int> vis;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void solution(){
    q.push(input);
    vis[input] = 0;
    while(!q.empty()){
        string u = q.front();   q.pop();
        if(u == output){
            cout<<vis[u]<<endl;
            return;
        }
        int index = u.find('.');
        int r = index / 3;
        int c = index % 3;
        for(int i = 0;i < 4;i++){
            string v = u;
            int r_ed = r + dr[i];   int c_ed = c + dc[i];
            int z_ed  = r_ed * 3 + c_ed;
            if(z_ed >= 0 && z_ed <= 8){
                char temp = v[index];
                v[index] = v[z_ed];
                v[z_ed] = temp;
                if(!vis.count(v)){
                    q.push(v);
                    vis[v] = vis[u] + 1;
                }
            }
        }
    }
    cout<<"-1"<<endl;
}

int main(){
    cin>>input>>output;
    solution();
    return 0;
}
