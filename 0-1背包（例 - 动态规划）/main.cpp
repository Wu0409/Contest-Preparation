//QUESTION: 0-1背包 https://www.bilibili.com/video/av62953142?from=search&seid=2928862538997502634

#include <iostream>
using namespace std;
int max_volume = 10;
int volume[] = {2,3,5,5};
int value[] = {2,4,3,7};

int table[5][16];
void solution(){
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= max_volume;j++){
            if(volume[i-1] <= j){
                table[i][j] = max(table[i-1][j] /*不拿*/,table[i-1][j-volume[i-1]] + value[i-1] /*拿，需要预留位置*/);
            }
            else{   //装不下
                table[i][j] = table[i-1][j];
            }
        }
    }
    cout<<"MaxSolution:"<<table[4][max_volume]<<endl;
}

void display(){
    int c = 10;
    cout<<"拿了如下价值的东西:"<<endl;
    for(int i = 4;i >= 1;i--){
        if(table[i][c] == table[i-1][c]){
            c = 10; //没有拿当前价值的物品
        }
        else{
            cout<<value[i-1]<<" ";
            c = c - volume[i-1];
        }
    }
}

int main() {
    solution();
    display();
    return 0;
}
