//备注：因为是填空题，直接使用了STL全家桶，速度较慢
//答案：20

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector <int> m = {0,1,2,3,4,5,6,7,8};
vector <int> answer = {0,8,7,6,5,4,3,2,1};
map <vector<int>,int> vis;
queue <vector <int>> q;

bool ok(vector<int> status){
    if(status == answer)    return true;
    return false;
}

void solution(vector <int> status = m){
    vis[status] = 0;
    q.push(status);
    while(!q.empty()){
        vector <int> u = q.front(); q.pop();
        int depth = vis[u];
        if(ok(u)){
            cout<<depth<<endl;
            return;
        }
        int index;
        for(int i = 0;i < 9;i++){
            if(u[i] == 0){
                index = i;
                break;
            }
        }

        for(int i = -2;i <= 2;i++){
            int ed = (index+9 + i) % 9;
            vector <int> v = u;
            swap(v[index],v[ed]);
            if(!vis.count(v)){
                vis[v] = depth + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    solution();
    return 0;
}
