//书本P199
//考察：路径寻找问题
//QUESTION：八数码问题

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

vector <int> Map = {2,6,4,1,3,7,0,5,8};
vector <int> target = {8,1,5,7,3,6,4,0,2};
queue <vector <int>> q;
map <vector <int>,bool> check; //查重
map <vector <int>,int> dis; //距离
map <vector <int>,vector <int>> pre; //记录节点的前驱

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
void print_ans(vector <int> u){
    vector <vector <int>> result;
    vector <int> temp = u;
    while(temp != Map){
        result.push_back(temp);
        temp = pre[temp];
    }
    result.push_back(Map);
    for(int i = result.size() - 1;i >= 0;i--){
        for(int j = 1;j <= 9;j++){
            cout<<result[i][j-1]<<" ";
            if(j % 3 == 0)  cout<<endl;
        }
        cout<<endl;
    }
    cout<<"共："<<dis[u]<<"步！"<<endl;
}
void solution(){
    q.push(Map);
    dis[Map] = 0;
    while(!q.empty()){
        vector <int> u = q.front(); q.pop();
        if(u == target){
            print_ans(u);
            return;
        }
        int z;
        for(z = 0;z < 9;z++){
            if(u[z] == 0)   break;
        }
        int r = z / 3;  int c = z % 3;
        for(int i = 0;i < 4;i++){
            int r1 = r + dr[i]; int c1 = c + dc[i]; //（r1，c1）与空格互换位置
            int z1 = r1 * 3 + c1;
            if(r1 >= 0 && r1 < 3 && c1 >= 0 && c1 < 3){
                vector <int> v = u;
                int temp = v[z1];
                v[z1] = v[z];
                v[z] = temp;    //互换位置
                if(!check.count(v)) {
                    check[v] = true;
                    dis[v] = dis[u] + 1;
                    pre[v] = u;
                    q.push(v);
                }
            }
        }
    }
    cout<<"failed!"<<endl;
}

int main() {
    solution();
    return 0;
}
