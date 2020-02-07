//书本P205
//考察：路径寻找问题
//QUESTION：万圣节后的早晨

//备注：仅限2个字母，可以设置虚拟节点强行构成三个节点

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
vector <char> Map= {'#','#','#','#','#',
                    '#','1','#','1','#',
                    '#','1','1','1','#',
                    '#','b','#','a','#',
                    '#','#','#','#','#'};

vector <char> target= {'#','#','#','#','#',
                       '#','a','#','b','#',
                       '#','1','1','1','#',
                       '#','1','#','1','#',
                       '#','#','#','#','#'};


int dr[5] = {0,-1,1,0,0};   //不动，上，下，左，右
int dc[5] = {0,0,0,-1,1};
map <vector <char>,int> Distance;
map <vector <char>,vector <char>> pre;
queue <vector <char>> q;


void print_ans(vector <char> u){
    vector <vector <char>> result;
    result.push_back(u);
    vector <char> temp = u;
    while(temp != Map){
        temp = pre[temp];
        result.push_back(temp);
    }
    int c = 1;
    for(int i = result.size()-1;i >= 0;i--) {
        for (char j:result[i]) {
            cout << j << " ";
            if (c % 5 == 0) {
                cout << endl;
            }
            c++;
        }
        cout << endl;
    }
    cout<<"共需要："<<Distance[u]<<"步！"<<endl;
}
void solution(int r,int c){
    vector <char> u = Map;
    Distance[u] = 0;
    q.push(u);
    while(!q.empty()){
        vector <char> u = q.front();    q.pop();
        if(u == target){
            print_ans(u);
            return;
        }
        int i;
        for(i = 0;u[i] != 'b';i++){}
        int z1 = i;
        for(i = 0;u[i] != 'a';i++){}
        int z2 = i;
        int r1 = z1 / 5;    int c1 = z1 % 5;
        int r2 = z2 / 5;    int c2 = z2 % 5;
        for(int i = 0;i < 5;i++){
            vector <char> v = u;
            int r1_ed = r1 + dr[i]; int c1_ed = c1 + dc[i];
            int z1_ed = r1_ed * 5 + c1_ed;
            char a = v[z1];
            if(!((r1_ed >= 0 && r1_ed <= 4) && (c1_ed >= 0 && c1_ed <= 4) && (v[z1_ed] == '1' || v[z1_ed] == a))) continue;
            int temp = v[z1_ed];    v[z1_ed] = v[z1];   v[z1] = temp;
            for(int j = 0;j < 5;j++){
                vector <char> w = v;
                int r2_ed = r2 + dr[j]; int c2_ed = c2 + dc[j];
                int z2_ed = r2_ed * 5 + c2_ed;
                char a = w[z2];
                if(!((r2_ed >= 0 && r2_ed <= 4) && (c2_ed >= 0 && c2_ed <= 4) && (v[z2_ed] == '1' || v[z2_ed] == a))) continue;
                int temp = w[z2_ed];    w[z2_ed] = w[z2];   w[z2] = temp;
                if(!Distance.count(w)){
                    pre[w] = u;
                    Distance[w] = Distance[u] + 1;
                    q.push(w);
                }
            }
        }
    }
}

int main() {
    solution(4,4);
}
