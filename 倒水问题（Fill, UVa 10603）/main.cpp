//书本P202
//考察：路径查找问题
//QUESTION：倒水问题

#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;
typedef struct node{    //记录状态
    int cup[3],dist; //dist目前倒水量
    node(int a1 = 0,int b1 = 0,int c1 = 0,int dist1 = 0){
        cup[0] = a1;    cup[1] = b1;    cup[2] = c1;
        dist = dist1;
    }
    bool operator < (const node& other)const{
        return dist > other.dist;
    }
};
map <node,node> pre;    //记录前驱，用于回溯输出结果
map <vector <int>,bool> ed; //查重
priority_queue <node> q;
const int cup[3] = {6,3,1}; //记录容量大小
void print_ans(node u){
    vector <node> ans;
    node temp = u;
    while(temp.dist != 0){  //倒水量==0，即开始
        ans.push_back(temp);
        temp = pre[temp];
    }
    for(int i = ans.size() - 1;i >= 0;i--){
        cout<<ans[i].cup[0]<<" "<<ans[i].cup[1]<<" "<<ans[i].cup[2]<<" "<<endl;
    }
    cout<<"倒水量："<<u.dist<<endl;
}
void solution(int a,int b,int c,int d){
    node u(a,b,c,0);
    q.push(u);
    while(!q.empty()){
        node u = q.top();   q.pop();
        if(u.cup[0] == d || u.cup[1] == d || u.cup[2] == d){
            print_ans(u);
            return;
        }
        for(int i = 0;i <= 2;i++){  //第几个杯子倒水
            if(u.cup[i] != 0){
                for(int j = 0;j <= 2 ;j++){
                    node v = u;
                    if(j != i && v.cup[j] < cup[j]){
                        int pour = cup[j] - v.cup[j];   //计算倒水量
                        if(pour > v.cup[i]){    //需要倒满杯子的水量大于了要倒出杯子的容量
                            pour = v.cup[i];
                        }
                        v.cup[i] -= pour;
                        v.cup[j] += pour;
                        v.dist = u.dist + pour;
                        vector <int> check = {v.cup[0],v.cup[1],v.cup[2]};
                        if(!ed.count(check)){
                            ed[check] = true;
                            pre[v] = u;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
}
int main() {
    solution(6,0,0,4);
    return 0;
}
