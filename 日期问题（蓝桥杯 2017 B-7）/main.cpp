//蓝桥杯2017B-7
/*
1960.1.1 - 2059.12.31
样例输入：
- - -
02/03/04
*/
#include <iostream>
#include <set>

using namespace std;

bool is_run(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

string solution(int a, int b, int c) {   //判断+生成字符串
    if (a >= 60) {
        a += 1900;
    } else {
        a += 2000;
    }
    if (b < 1 || b > 12) return "";
    if (c < 1 || c > 31) return "";

    switch (b) {
        case 2:
            if (is_run(a)) {
                if (c > 29) return "";
            } else {
                if (c > 28) return "";
            }
            break;
        case 4:
            if (c > 30) return "";
            break;
        case 6:
            if (c > 30) return "";
            break;
        case 9:
            if (c > 30) return "";
            break;
        case 11:
            if (c > 30) return "";
            break;
        default:
            break;
    }
    string a1 = to_string(a);
    string b1 = to_string(b);
    string c1 = to_string(c);
    if (b1.length() == 1) b1 = "0" + b1;
    if (c1.length() == 1) c1 = "0" + c1;
    return a1 + "/" + b1 + "/" + c1;
}

int main() {
    string in;
    cin >> in;
    int a = (in[0] - '0') * 10 + (in[1] - '0');
    int b = (in[3] - '0') * 10 + (in[4] - '0');
    int c = (in[6] - '0') * 10 + (in[7] - '0');
    string case1 = solution(a, b, c);
    string case2 = solution(c, a, b);
    string case3 = solution(c, b, a);
    set<string> ans;
    if (case1 != "") ans.insert(case1);
    if (case2 != "") ans.insert(case2);
    if (case3 != "") ans.insert(case3);
    for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
