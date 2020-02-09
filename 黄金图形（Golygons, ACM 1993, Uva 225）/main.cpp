//书本P214
//QUESTION：黄金图形

#include <iostream>
#include <vector>
using namespace std;
typedef struct point{
    int x,y;
    point(int x1 = 0,int y1 = 0):x(x1),y(y1){}
    bool operator == (point& other) const{
        return (x == other.x) && (y == other.y);
    }
};
int n = 8;  //步数
vector <string> ans;
vector <point> obstacle;
string direction = "NESW";  //上下左右

point start;    //初始点
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void solution(point status,string result = "",int last_dir = -1,int depth = 0){
    //检查是否遇到障碍物
    int last_x,last_y;
    if(last_dir == 1 || last_dir == 3){
        last_x = status.x - dx[last_dir] * (depth - 1);    last_y = status.y;
    }
    if(last_dir == 0 || last_dir == 2){
        last_x = status.x;  last_y = status.y - dy[last_dir] * (depth - 1);
    }
    for(point i:obstacle){  //判断是否遇到障碍物
        if(i.x >= min(last_x,status.x) && i.x <= max(last_x,status.x) && i.y == last_y)   return;
        if(i.y >= min(last_y,status.y) && i.y <= max(last_y,status.y) && i.x == last_x)   return;
    }

    if(depth == n){
        if(status == start){
            ans.push_back(result);
        }
        return;
    }

    if(depth == 0) {    //最开始的一步四个方向都能选
        for (int i = 0; i < 4; i++) {  //上下左右
            result += direction[i];
            int dis = depth + 1;    //当前移动的距离
            point moved(status.x + (dx[i] * dis), status.y + (dy[i] * dis));
            solution(moved, result,i,depth + 1);
            result.pop_back();
        }
    }
    else{   //其余步不能和上一次移动方向一致或后退
        for (int i = 0; i < 4; i++) {  //上下左右
            if(i == last_dir || i == ((last_dir + 2) % 4)) continue;
            result += direction[i];
            int dis = depth + 1;    //当前移动的距离
            point moved(status.x + (dx[i] * dis), status.y + (dy[i] * dis));
            solution(moved, result,i, depth + 1);
            result.pop_back();
        }
    }
}

int main() {
    //样例输入
    point o1(-2,0); point o2(6,-2);
    obstacle.push_back(o1); obstacle.push_back(o2);
    solution(start);
    for(string i:ans){
        for(int c = 0;c < i.length();c++){
            cout<<i[c]<<"";
        }
        cout<<endl;
        point out;
        cout<<"("<<out.x<<","<<out.y<<") -> ";
        int count = 1;
        for(int j = 0;j < i.length();j++){
            if(i[j] == 'N')         out.y += 1 * count;
            else if(i[j] == 'E')    out.x += 1 * count;
            else if(i[j] == 'S')    out.y += -1 * count;
            else if(i[j] == 'W')    out.x += -1 * count;
            if(out.x != 0 && out.y != 0)    cout<<"("<<out.x<<","<<out.y<<") -> ";
            count++;
        }
        cout<<"("<<out.x<<","<<out.y<<")"<<endl;
    }
}
