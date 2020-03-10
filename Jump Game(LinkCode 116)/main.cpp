//LinkCode 116 Jump Game
#include <iostream>

using namespace std;
int a[] = {2, 3, 1, 1, 4};
int n = 4;
int u[5];

bool solution(int in){
    if(in == n) return true;
    if(u[in] != -1) return u[in];
    u[in] = 0;
    for(int i = 1;i <= a[in];i++){
        if(solution(in + i)){
            u[in] = 1;
        }
    }
    return u[in];
}

int main() {
    memset(u,-1,sizeof(int[5]));
    cout << solution(0) << endl;
    return 0;
}
