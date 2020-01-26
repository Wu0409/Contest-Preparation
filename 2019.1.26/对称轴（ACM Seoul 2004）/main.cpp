//书本P135
//考察：STL
//QUESTION：找对称轴

#include <iostream>
#include <vector>

typedef struct point{
    int x;
    int y;
    point(int a,int b):x(a),y(b){}
    bool operator < (const point& other) const{
        return x < other.x;
    }
};
using namespace std;

int main() {
    //point a(-2,5);  point b(0,0);   point c(2,3);   point d(4,0);   point e(6,5);
    //vector <point> point_list = {a,b,c,d,e};
    point a(0,0);  point b(0,4);   point c(2,3);   point d(4,0);
    vector <point> point_list = {a,b,c,d};
    bool is_xsym = true;
    bool is_ysym = true;

    vector <int> x_list;
    for(int i = 0;i < point_list.size();i++){
        x_list.push_back(point_list[i].x);
    }
    sort(x_list.begin(),x_list.end());
    if(x_list.size() % 2 == 1){ //奇数个点情况，需要判断最中间的点
        int x_sym = (x_list[0] + x_list[x_list.size()-1]) / 2;  //如果对称的对称轴
        /*  测试对称轴
        cout<<x_sym<<endl;
         */
        for(int i = 0;i <= (x_list.size() / 2) - 1;i++){
            /*  输出两点到对称轴的距离
            cout<<(abs(x_list[i] - x_sym))<<":"<<(abs(x_list[x_list.size()-1 - i]) - x_sym)<<endl;
             */
            if(abs(x_list[i] - x_sym) != abs(x_list[x_list.size()-1 - i]) - x_sym){
                is_xsym = false;
                break;
            }
        }
        //判断x最中间的点
        if(x_list[x_list.size()/2] != x_sym){
            is_xsym = false;
        }
    }
    else{
        int x_sym = (x_list[0] + x_list[x_list.size()-1]) / 2;  //如果对称的对称轴
        for(int i = 0;i <= (x_list.size() / 2) - 1;i++){
            if(abs(x_list[i] - x_sym) != abs(x_list[x_list.size()-1 - i]) - x_sym){
                is_xsym = false;
                break;
            }
        }
    }
    //cout<<is_xsym<<endl;  //判断x方向是否对称
    if(is_xsym) {
        sort(point_list.begin(),point_list.end());
        vector<int> y_list;
        for (int i = 0; i < point_list.size(); i++) {
            y_list.push_back(point_list[i].y);
        }
        for(int i = 0;i <= (y_list.size() / 2) - 1;i++){
            if(y_list[i] != y_list[x_list.size()-1 - i]){
                is_ysym = false;
                break;
            }
        }
    }
    if(is_xsym && is_ysym){
        cout<<"SYMMETRICAL!"<<endl;
    }
    else{
        cout<<"NOT SYMMETRICAL!"<<endl;
    }
    return 0;
}