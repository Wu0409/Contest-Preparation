//书本：P197
//考察：回溯法，剪枝
//QUESTION：带宽

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int Map[8][8] = {{0, 1, 0, 0, 0, 1, 0, 0},
                 {1, 0, 1, 0, 0, 0, 1, 0},
                 {0, 1, 0, 1, 0, 0, 0, 0},
                 {0, 0, 1, 0, 1, 0, 1, 0},
                 {0, 0, 0, 1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 0, 0, 1, 1},
                 {0, 1, 0, 1, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 1, 0, 0}};
int current_min = 10;   //目前找到的最小带宽
map <int,vector <int>> record;

int to_map(int input){
    return input - 1;
}

void solution(vector <int> target,vector <int> result,int index = 0){
    if(index == 8){
        int max = 0;
        for(int i = 0;i < result.size();i++){
            for(int j = 0;j < result.size();j++){   //检索map是否连通 map[i][j]（i== j）没有影响，也是0
                if(Map[to_map(result[i])][to_map(result[j])] == 1 && abs(j-i) > max){
                    max = abs(j-i);
                }
            }
        }
        record[max] = result;
        return;
    }
    for(int i = 0;i < 8 - index;i++){
        for(int i = 0;i < result.size();i++){   //剪枝
            for(int j = 0;j < result.size();j++){   //检索map是否连通 map[i][j]（i== j）没有影响，也是0
                if(Map[i][j] == 1 && abs(j-i) > current_min)    return;
            }
        }
        vector <int> temp = target;
        result.push_back(temp[i]);
        temp.erase(temp.begin()+i);
        solution(temp,result,index + 1);
        result.pop_back();
    }
}

int main() {
    vector <int> target = {1,2,3,4,5,6,7,8};    //A B C D E F G H
    vector <int> result;
    solution(target,result);
    for(int i = 0;i <= 8;i++){
        if(record.count(i)){
            cout<<i<<endl;
            for(int j:record[i]){
                cout<<j<<" ";
            }
            cout<<endl;
            break;
        }
    }
    return 0;
}
