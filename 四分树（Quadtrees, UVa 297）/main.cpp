//书本P160
//考察
//QUESTION：四分树

//buf("画布")设置的大小不一样，结果不一样

#include <iostream>
using namespace std;
const int len = 4;
int buf[len][len];
int Const = 0;  //input的计数器
int result = 0;

void draw(const string input,int x,int y,int width){
    char ch = input[Const++];
    if(ch == 'p'){
        draw(input,x,(y + width/2),width/2);    //1
        draw(input,x,y,width/2);    //2
        draw(input,(x + width/2),y,width/2);    //3
        draw(input,(x + width/2),(y + width/2),width/2);    //4
    }
    else if(ch == 'f'){
        for(int i = x;i < (x+width);i++){
            for(int j = y;j < (y+width);j++){
                if(buf[i][j] == 0){ //白色的变成黑色的
                    buf[i][j] = 1;
                    result++;   //黑的不会再变成白的，所以黑色像素点只会增加不会减少
                }
            }
        }
    }
}

int main(){
    //样例输入
    string input1 = "ppeeefpffeefe";
    draw(input1,0,0,len);
    for(int m = 0;m <= 3;m++){
        for(int n = 0;n <= 3;n++){
            cout<<buf[m][n]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    Const = 0;  //计数器重置
    string input2 = "pefepeefe";
    draw(input2,0,0,len);
    for(int m = 0;m <= 3;m++){
        for(int n = 0;n <= 3;n++){
            cout<<buf[m][n]<<" ";
        }
        cout<<endl;
    }
    cout<<result<<endl;
}