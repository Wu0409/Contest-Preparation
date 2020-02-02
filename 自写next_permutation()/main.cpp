//实现STL的next_permutation()

#include <iostream>
#include <vector>
using namespace std;
void permutation(vector <int> target,vector <int> result){
    if(target.size() == 1){
        result.push_back(target[0]);
        for(int i : result){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 0;i < target.size();i++){
        vector <int> temp = target;
        result.push_back(temp[i]);
        temp.erase(temp.begin()+i);
        permutation(temp,result);
        result.pop_back();
    }
}
int main() {
    vector <int> target = {1,2,3};
    vector <int> result;
    permutation(target,result);
    return 0;
}
