//书本：P195
//考察：回溯法
//QUESTION：困难的串

#include <iostream>
using namespace std;
int n = 7,l = 3;
char* charater;
bool is_ok(const string result,char add1){
    string add = new char(add1);
    string verify = result + add;
    for(int i = 1;i <= verify.length() / 2;i++){
        string sub = "";
        for(int j = verify.length() - i;j <= verify.length() - 1;j++){
            sub += verify[j];
        }
        string sub_front = verify.substr(verify.length() - 2*i,sub.length());
        if(sub == sub_front) return false;
    }
    return true;
}
void solution(string result = "",int index = 0){
    if(result.length() == n){
        cout<<result<<endl;
        return;
    }
    if(index == 0){
        for(int i = 0; i< 3;i++){
            result += charater[i];
            solution(result,index + 1);
            result.pop_back();  //递归返回（不满足）后，还原
        }
    }
    else{
        for(int i = 0; i< 3;i++){
            if(is_ok(result,charater[i])){
                result += charater[i];
                solution(result,index + 1);
                result.pop_back();  //递归返回（不满足）后，还原
            }
        }
    }
}

int main() {
    charater = new char(l);
    for(int i = 0;i <l;i++){
        charater[i] = 65 + i;
    }
    solution();
    return 0;
}
