//书本：P183
//考察：简单枚举
//QUESTION：分数拆分

#include <iostream>
#include <vector>
using namespace std;
void solution(int k){
    for(int y = k + 1;y <= 2*k;y++){
        double x = 1.0 / (1.0/k - 1.0/y);
        if(k*y%(y-k) == 0){
            cout<<"1/"<<k<<" = "<<"1/"<<x<<" + "<<"1/"<<y<<endl;
        }
    }
}

int main() {
    int k;
    cout<<"k:"; cin>>k;
    solution(k);
    return 0;
}
/*
int main() {
    int k;
    while(scanf("%d", &k) == 1 && k) {
        vector<int> X, Y;
        for(int y = k+1; y <= k*2; y++) {
            // 1/k = 1/x + 1/y => x = ky/(y-k)
            if(k*y%(y-k) == 0)
            { X.push_back(k*y/(y-k)); Y.push_back(y); }
        }
        printf("%d\n", X.size());
        for(int i = 0; i < X.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
    }
    return 0;
}
 */
