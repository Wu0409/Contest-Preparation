//书本P157
//考察：递归
//QUESTION：天平

#include <iostream>
using namespace std;
bool solve(int& w){ //引用是精髓！！！
    int w1,d1,w2,d2;
    bool left = true, right = true;
    cin>>w1>>d1>>w2>>d2;
    w = w1 + w2;
    if(w1 == 0){
        left = solve(w1);
    }
    if(w1 == 0){
        right = solve(w2);
    }
    return left && right && (w1 * d1 == w2 * d2);
}

int main() {
    int w;
    if(solve(w)){
        cout<<"BALANCED!"<<endl;
    }
    else{
        cout<<"UNBALANCED"<<endl;
    }
    return 0;
}