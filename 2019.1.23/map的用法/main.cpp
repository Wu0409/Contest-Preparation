#include <iostream>
#include <map>

using namespace std;

int main() {
    map <string,int> test;
    //单个插入
    test["一"] = 1;
    //使用insert（）插入：
    test.insert(pair<string,int>("二",2));
    //查找是否存在该键 test.count()
    cout<<test.count(("一"))<<endl;
}