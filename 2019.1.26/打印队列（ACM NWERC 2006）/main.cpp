//书本P136
//考察STL
//QUESTION:打印队列

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> priority = {1,1,9,1,1,1};
    int target = 0;
    int position = target;

    int time = 1;
    while(!(position == 0 && priority[0] >= *max_element(priority.begin(),priority.end()))){//循环到头，且没有一个元素比它大
        for(int i = 0;i < priority.size();i++){
            cout<<priority[i]<<" ";
        }
        cout<<endl;
        if(position == 0){  //"目标"在队首但不是优先级最大的元素
            int temp = priority[0];
            priority.erase(priority.begin());
            priority.push_back(temp);
            position = priority.size() - 1;
        }
        else if(priority[0] >= *max_element(priority.begin(),priority.end())){  //不是目标，但是是是最大元素，处理该任务
            priority.erase(priority.begin(),++priority.begin());
            position--;
            time++;
        }
        else {  //不是该目标，而且不是最大的元素
            int temp = priority[0];
            priority.erase(priority.begin());
            priority.push_back(temp);
            position--;
        }
    }
    cout<<time<<endl;
}