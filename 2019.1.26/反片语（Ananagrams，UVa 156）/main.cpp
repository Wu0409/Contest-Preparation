//书本P113
//考查内容：映射：map
//QUESTION：找到如下单词，该单词不能通过字母重排，变成其他单词，判断时大小写不限，输出时保留输入中的大小写。

#include <iostream>
#include <vector>
#include <map>
#include <ctype.h>
#include <algorithm>

using namespace std;

map <string,int> cnt;
vector <string> wordlist;

string standardize(const string& s){
    string ans = s;
    for(int i = 0;i < ans.length();i++){
        ans[i] = tolower(ans[i]);   //全部变成小写
    }
    sort(ans.begin(),ans.end());    //重新排序
    return ans;
}


int main() {
    string s;
    while(cin>>s){
        if(s[0] == '#'){    //设置结束符
            break;
        }
        else{
            wordlist.push_back(s);
            string r = standardize(s);
            if(!cnt.count(r)){  //没有该键
                cnt[r] = 0;
            }
            cnt[r]++;   //存在该键（或刚刚添加了的键）对应的值
        }
    }
    vector <string> answer;
    for(int i = 0;i < wordlist.size();i++){
        if(cnt[standardize(wordlist[i])] == 1){
            answer.push_back(wordlist[i]);
        }
    }
    sort(answer.begin(),answer.end());
    for(int i = 0;i < answer.size();i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}