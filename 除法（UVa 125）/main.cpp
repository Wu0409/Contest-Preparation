//书本P182
//考察：暴力求解法 - 简单枚举
//QUESTION：除法 abcde/fghij = n

//备注：只需要 fghij 不需要枚举abcde（n * fghij）

#include <iostream>
#include <map>
using namespace std;
void solution(int n){
    for(int i = 1282;i < 100000;i++){
        map<char,bool> used;
        int result = i;
        int result1 = n * result;
        string r0 = to_string(result);
        string r1 = to_string(result1);
        string r3 = r0 + r1;
        if(r0.length() > 5 || r1.length() > 5){
            continue;
        }
        if(r3.length() == 9)    r3.insert(0,"0");
        bool ok = true;
        for(int i = 0;i < r3.length();i++){
            if(used.count(r3[i])){
                ok = false;
                break;
            }
            used[r3[i]] = true;
        }
        if(ok == 1){
            cout<<result1<<" / "<<result<<" = "<<n<<endl;
        }
    }
}
int main(){
    int n;  cin>>n;
    solution(n);
    return 0;
};
