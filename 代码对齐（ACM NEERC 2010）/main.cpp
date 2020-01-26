//书本P135
//考察：STL,sstream
//QUESTION：代码对齐（Alignment of Code， ACM/ICPC NEERC 2010， UVa1593）

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int lmax[255];  //每列最长字符的长度
vector <string> content[1000];

int main(){
    int i = 0;  //行数的计数器
    int k = 0;  //列的计数器
    string input,buf;
    while(getline(cin,input) && input != "#"){  // "#" 终止
        k = 0;
        stringstream ss(input);
        while(ss >> buf){
            int len = buf.length();
            lmax[k] = max(lmax[k],len);
            content[i].push_back(buf);
            k++;
        }
        i++;
    }
    //对齐输出
    for(int j = 0;j < i;j++){
        for(int n = 0;n < content[j].size();n++){
            cout<<content[j][n];
            if(content[j][n].length() < lmax[n]){
                int add = lmax[n] - content[j][n].length();
                while(add){ //补充的" "
                    cout<<" ";
                    add--;
                }
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}