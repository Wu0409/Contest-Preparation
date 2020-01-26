//书本P135
//考察：STL
//QUESTION：Ducci序列

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool zero(const vector <int>& newer){   //判断元组是否都是0
    for(int i = 0;i < newer.size();i++){    //循环遍历
        if(newer[i] != 0){  //一旦找到非0 -> 返回false - 不都为0
            return false;
        }
    }
    return true;
}

int main() {
    //初始化元组
    int num;
    map <vector <int>,bool> record;
    cout<<"输入n元组：n = "; cin>>num;
    int k = num;
    vector <int> list;
    while(k){   //输入元组
        int i;
        cin>>i;
        list.push_back(i);
        k--;
    }
    record[list] = true;    //加入map
    vector <int> pre = list;
    int i = 0;
    //检查
    while(i != 1001){
        vector <int> newer;
        for(int i = 0;i < num - 1;i++){ //生成新元组
            int temp = abs(pre[i] - pre[i+1]);
            newer.push_back(temp);
        }
        newer[num - 1] = abs(pre[num - 1] - pre[0]);

        for(int i = 0;i < num;i++){ //循环输出新元组
            cout<<newer[i]<<" ";
        }
        cout<<endl;

        pre = newer;    //作为前一个被记录
        pre[num - 1] = newer[num-1];

        if(record.count(newer)){    //出现之前出现过的，后面一定是循环
            cout<<"LOOP!"<<endl;
            break;
        }
        record[newer] = true;

        if(zero(newer)){    //判断是否都是0
            cout<<"ZERO!"<<endl;
            break;
        }

        i++;
    }
    return 0;
}