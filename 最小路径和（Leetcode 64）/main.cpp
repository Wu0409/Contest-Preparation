//QUESTIOn：最小路径和

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> grid;

void init() {
    vector<int> a = {1, 3, 1};  grid.push_back(a);
    vector<int> b = {1, 5, 1};  grid.push_back(b);
    vector<int> c = {4, 2, 1};  grid.push_back(c);
}

int u[3][3];
int target_r = 3;
int target_c = 3;

int solution(int r = 0,int c = 0){
    if(r >= target_r || c >= target_c) return 1<<30;
    if(r == (target_r - 1) && c == (target_c - 1))  return grid[r][c];
    int &ans = u[r][c];
    if(ans != -1)   return ans;
    ans = min(solution(r+1,c),solution(r,c+1)) + grid[r][c];
    return ans;
}

int main() {
    init();
    memset(u,-1, sizeof(int[3][3]));
    cout<<solution()<<endl;
    return 0;
}
