//QUESTION:不同路径2 Leetcode 63

#include <iostream>
#include <vector>
using namespace std;
vector <vector<int>> input;
int u[100][100];
int target_r,target_c;

void init(){
    vector <int> a = {0,0,0};   input.push_back(a);
    vector <int> b = {0,1,0};   input.push_back(b);
    vector <int> c = {0,0,0};   input.push_back(c);
    target_r = input.size();
    target_c = input[0].size();
}

int solution(int m = 0,int n = 0){
    if(m >= target_r || n >= target_c)    return 0;
    if(input[m][n] == 1)    return 0;
    if(m == (target_r - 1) && (n == target_c - 1))  return 1;
    int &ans = u[m][n];
    if(ans != -1)   return ans;
    ans = 0;
    ans += solution(m+1,n) + solution(m,n+1);
    return ans;
}

int main() {
    memset(u,-1, sizeof(int[100][100]));
    init();
    cout<<solution()<<endl;
    return 0;
}
