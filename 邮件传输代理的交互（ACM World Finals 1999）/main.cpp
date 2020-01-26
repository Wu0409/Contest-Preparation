//书本P130
//考察STL的使用
//QUESTION:模拟邮件传输代理的交互（具体见书本）

//备注：简易实现

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void address(const string& receiver,string& name,string& mta){
    int index = receiver.find('@'); //'@'的索引值
    name = receiver.substr(0,index);
    mta = receiver.substr(index);
}

int main() {
    map <string,vector <string>> list;  //mta - 该mta的username
    map <string,int> mta_list;  //检查是否已经遍历
    vector <string> user;   //收件人列表
    //创建收件人列表
    string receiver;    //收件人
    while(cin>>receiver && receiver != "*"){    //"*"为结束符
        user.push_back(receiver);
        string username;
        string mta;
        address(receiver,username,mta);
        if(!list.count(mta)){   //没有该键
            vector <string> userlist;
            list[mta] = userlist;
            list[mta].push_back(username);
        }
        else{   //存在该键
            list[mta].push_back(username);
        }
    }
    getline(cin,receiver);  //把流中的"*"吃掉

    for(int i = 0;i < user.size();i++){
        string a,b;
        address(user[i],a,b);
        if(!mta_list.count(b)){ //没有访问过代理服务器
            cout<<"->"<<b<<endl;
            cout<<"user:"<<endl;
            for(int j = 0;j < list[b].size();j++){
                cout<<list[b][j]<<" ";
            }
            cout<<endl;
        }
        mta_list[b] = 1;
    }


    return 0;
}