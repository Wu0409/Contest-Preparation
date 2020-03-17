//QUESTION:丑数2 Leetcode 264

#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n) {
    vector<int> u(1, 1);
    int l1 = 0, l2 = 0, l3 = 0;
    for(int i = 1;i < n;i++){
        int v = min(2 * u[l1],min(3 * u[l2],5 * u[l3]));
        u.push_back(v);
        if(v == 2 * u[l1])  l1++;
        if(v == 3 * u[l2])  l2++;
        if(v == 5 * u[l3])  l3++;
    }
    return *(u.end()-1);
}

int main() {
    cout << nthUglyNumber(10) << endl;
    return 0;
}
