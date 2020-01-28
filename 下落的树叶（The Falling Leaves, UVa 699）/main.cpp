//书本P159
//考察：递归
//QUESTION:下落的树叶

#include <iostream>
#include <map>

using namespace std;
map <int,int> sum;  //记录和
int input[] = {8,2,9,-1,-1,6,5,-1,-1,12,-1,-1,3,7,-1,-1,-1};    //书本上的样例输入
int Count = -1;

void solve(int position){
    Count++;
    if(input[Count] == -1){
        return;
    }
    if(sum.count(position)){
        sum[position] += input[Count];
    }
    else{
        sum[position] = input[Count];
    }
    solve(position - 1);    //左
    solve(position + 1);    //右
}

int main() {
    solve(0);
    //找最右叶子所在的位置
    int count = 0;
    while(1){
        if(input[count] == -1 && input[count + 1] == -1){
            break;
        }
        count++;
    }
    int left = - (count - 1);
    for(int i = left;sum.count(i) == 1;i++){
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    return 0;
}