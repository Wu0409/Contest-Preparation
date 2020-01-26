//书本：P135
//考察：STL
//QUESTION:复合词

//样例输入：a,alien,born,less,lien,never,nevertheless,new,newborn,the,zebra
//输出：alien,nevertheless,newborn

//备注：https://blog.csdn.net/a1061747415/article/details/25920267 有第一种使用set集合的方式

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    vector <string> dict = {"a","alien","born","less","lien","never","nevertheless","new","newborn","the","zebra"};
    string test = "abcdefg";

    map <string,bool> all_word;
    for(int i = 0;i < dict.size();i++){ //初始化字典
        all_word[dict[i]] = true;
    }
    for(int i = 0;i < dict.size();i++){
        if(dict[i].length() >= 2) {
            string target = dict[i];
            string first = "";  //如果有合成词，则是第一个
            string second = "";  //如果有合成词，则是第二个
            bool is_first = false;  bool is_second = false;
            int j,k;
            for (j = 0; j < target.length();j++) {  //找第一个词
                first += target[j];
                if(all_word.count(first)){
                    is_first = true;
                    break;
                }
            }
            second = target.substr(j);  //后面的部分即是second，直接判断该second是否存在即可
            if(all_word.count(second)){
                is_second = true;
            }
            if(is_first == 1 && is_second == 1){    //如果first和second都找到，则该单词是复合词
                cout<<dict[i]<<endl;
            }
        }
    }
    return 0;
}