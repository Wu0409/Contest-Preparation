//QUESTION:LintCode 114 Unique Paths

#include <iostream>

using namespace std;
int u[100][100];
int r0 = 0, c0 = 0;
int r1 = 3, c1 = 4;

void init() {
    memset(u, -1, sizeof(int[100][100]));
}

int solution(int r = r0, int c = c0) {
    if(r > r1 || c > c1)  return 0;
    if(r == r1 && c == c1) return 1;
    int &ans = u[r][c];
    if(ans != -1)   return ans;
    ans = solution(r+1,c) + solution(r,c+1);
    return solution(r+1,c) + solution(r,c+1);
}

int main() {
    init();
    scanf("%d%d",&r1,&c1);    --r1;--c1;
    cout<<"Result:"<<solution()<<endl;
    return 0;
}
