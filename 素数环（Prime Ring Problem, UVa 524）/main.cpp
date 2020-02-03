//书本P194
//考察：回溯法
//QUESTION：素数环

#include <iostream>
#include <vector>

using namespace std;
bool is_prime(int n){   //判断是否是素数
    bool isPrime = true;
    for(int i = 2; i <= n / 2; ++i){
        if(n % i == 0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
void solution(const vector <int>& test,vector <int> result,int len,int index = 0){
    if(index == len){
        if(is_prime(result[result.size()-1] + result[0])) {
            for (int i:result) {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    if(index == 0) {    //第一个不需要判断
        for(int i = 0;i < test.size();i++) {
            vector<int> temp = test;
            result.push_back(temp[i]);
            temp.erase(temp.begin() + i);
            solution(temp, result, len,index + 1);
            result.pop_back();
        }
    }
    else{
        for(int i = 0;i < test.size();i++) {
            vector<int> temp = test;
            if(is_prime(result[index - 1] + temp[i])){
                result.push_back(temp[i]);
                temp.erase(temp.begin() + i);
                solution(temp, result, len,index + 1);
                result.pop_back();
            }
        }
    }
}

int main(){
    vector <int> test = {1,2,3,4,5,6};
    vector <int> result;
    solution(test,result,test.size());
}

/*
//生成 - 测试法
//备注：未完善，因为是个环，所以会有重复现象
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n){
    bool isPrime = true;
    for(int i = 2; i <= n / 2; ++i){
        if(n % i == 0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
int main() {
    int test[] = {1,2,3,4,5,6};
    do{
        bool ok = true;
        for(int i = 0;i <= 4;i++){
            if(!is_prime(test[i] + test[i+1]))  ok = false;
        }
        if(!is_prime(test[5] + test[0]))  ok = false;
        if(ok){
            for(int i:test){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }while(next_permutation(test,test + 6));
    return 0;
}
*/