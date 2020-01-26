//书本P120
//考查内容：优先队列
//题目：不能被除了2，3，5以外数字整除的数

//key：对于任何丑数x，2x，3x，5x也都是丑数
//需要判断：一个丑数是否已经被生成过，本题使用map查重，在queue中不方便查重
//priority_queue中，我们不是用来存放第0-1500个丑数，而是不断向后放，取头（因为是数越小优先级越大优先队列）
//如果是第1500输出，不是1500，通过2x，3x，5x 生成新的丑数放入优先队列

#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int coeff[3] = {2,3,5};   //基数
priority_queue <long long,vector<long long>,greater<long long>> pq;
map <long,long> mp;

int main() {
    pq.push(1);
    for(int i = 1;;i++){
        long long x = pq.top();   pq.pop();
        if(i == 1500){
            cout<<x<<endl;
            break;
        }
        else{
            for(int j = 0;j < 3;j++){
                long long x2 = x * coeff[j];
                if(!mp.count(x2)){
                    mp[x2] = 1;
                    pq.push(x2);
                }
            }
        }
    }
    return 0;
}