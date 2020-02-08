//书本P210
//考察：
//QUESTION：宝箱

//备注：这个写法在数字很小，而n很大时，枚举量太大

#include <iostream>
#include <vector>
#include <map>

using namespace std;
//体积 - 价值
int s1 = 34,v1 = 34;    //option1
int s2 = 5, v2 = 3;     //option2
int current_max = 0;    //当前最优解
vector <int> ans;

int all_value(vector <int> result){
    int value = 0;
    for(int i = 0;i < result.size();i++){
        result[i] == 1 ? value += v1 : value += v2;
    }
    return value;
}

void solution(int leftover,vector <int> result){
    if(leftover < 0)    return;
    int minimum = min(s1,s2);   int maximum = max(s1,s2);
    int opt_min,opt_max;
    minimum == s1? opt_min = 1,opt_max = 2 : opt_min = 2,opt_max = 1;
    if(leftover < minimum){   //装不下任何东西
        int all_v = all_value(result);
        if(all_v > current_max){    //找到更好的解
            current_max = all_v;
            ans = result;  //放入答案
        }
        return;
    }
    if(leftover >= minimum){
        if(leftover < maximum){ //只能选择小的价值的
            result.push_back(opt_min);
            solution(leftover - minimum,result);
        }
        if(leftover >= maximum){
            result.push_back(opt_min);
            solution(leftover - minimum,result);
            result.pop_back();

            result.push_back(opt_max);
            solution(leftover - maximum,result);
            result.pop_back();
        }
    }
}

int main() {
    vector <int> result;
    solution(100,result);
    //输出结果
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"总价值："<<all_value(ans)<<endl;
    return 0;
}
