//QUESTION:三角形最小路径和 Leetcode120

#include <iostream>
#include <vector>
using namespace std;

vector<vector <int>> input = {};
void init(){
    vector <int> a = {2};   input.push_back(a);
    vector <int> b = {3,4};   input.push_back(b);
    vector <int> c = {6,5,7};   input.push_back(c);
    vector <int> d = {4,1,8,3};   input.push_back(d);
}

int minimumTotal(vector<vector<int>>& triangle = input) {
    vector <int> dp = *(triangle.end()-1);
    int size = (triangle.end()-2)->size();
    for(int i = triangle.size() - 2;i >= 0;i--){
        vector <int> temp(size,0);
        for(int j = 0;j < size;j++){
            temp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
        }
        dp = temp;
        size--;
    }
    return dp[0];
}


int main() {
    init();
    cout<<minimumTotal()<<endl;
    return 0;
}
