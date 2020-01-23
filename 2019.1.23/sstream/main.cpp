//sstream

#include <iostream>
#include <sstream>

using namespace std;
int main() {
    stringstream ss;

    cout<<"逐行读取："<<endl;
    string out;
    string a = "这是第一行\n这是第二行\n这是第三行\n";
    int count = 3;
    while(count){
        ss<<a;
        if(ss.fail()){
            break;
        }
        ss>>out;
        cout<<out<<endl;
        count --;
    }

    stringstream stream;
    cout<<"字符串->整型："<<endl;
    int out1;
    stream<<"123";
    stream>>out1;
    cout<<out1<<endl;
}