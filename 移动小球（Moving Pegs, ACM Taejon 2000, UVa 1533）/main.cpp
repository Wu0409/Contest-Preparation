//书本P217
//QUESTION：移动小球

#include <iostream>
#include <vector>
using namespace std;
bool input[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ;
int num[6] = {1,2,4,7,11,16};   //记录每一层首位置的序号
int limit,empty;
int i = 0;
typedef struct joint{
    int right[5];//左下到右上
    int left[5];//右下到左上
    int hor[4];
    int l1,r1,h1;
    joint(const int from = i++):l1(0),r1(0),h1(0){
        int i = 0;  while(num[i] <= from){i++;} //i记录了当前的层数
        int from1 = from;   for(int t = 5;t > i;t--){from1 += t;}
        int from2 = from;   for(int t = 4;t > i-1;t--){from2 += t;}
        int i1 = 0;  while(num[i1] <= from1){i1++;}
        int i2 = 0;  while(num[i2] <= from2){i2++;}
        left[l1++] = from1;
        int stl = i1;
        for(int s = i1;s >= 2;s--){
            stl--;
            if((from1 - s) >= num[stl-1] && (from1 - s) < num[stl]){
                if(from1 - s != from)   left[l1++] = from1 - s;
                from1 -= s;
            }
        }
        right[r1++] = from2;
        int str = i2;
        for(int s = i2 - 1;s >= 1;s--){
            str--;
            if((from2 - s) >= num[str-1] && (from2 - s) < num[str]){
                if(from2 - s != from)   right[r1++] = from2 - s;
                from2 -= s;
            }
        }
        if(i <= 5){
            for(int h = num[i-1];h < num[i];h++){
                if(h != from)  hor[h1++] = h;
            }
        }
    }
};
joint list[16];
bool ed[100000][16];
int ed_num = -1;

bool count(bool in[16]){
    for(int i = 0;i <= ed_num;i++){
        if(!memcmp(ed[i],in,sizeof(bool[16]))){
            return true;
        }
    }
    return false;
}

bool judge(){
    for(int i = 1;i < 16;i++){
        if(input[i] == 1 && i != empty) return false;
    }
    return true;
}

int is_ok(int from,int to){
    for(int i:list[to].left){
        if(i == from)   return 1;
    }
    for(int i:list[to].right){
        if(i == from)   return 2;
    }
    for(int i:list[to].hor){
        if(i == from)   return 3;
    }
    return 0;
}

bool solution(int depth = 0,string result = ""){
    if(depth == limit){
        if(judge()){
            cout<<"done"<<endl;
            cout<<result<<endl;
            return true;
        }
        else return false;
    }
    //得到空洞的编号
    vector <int> index;
    for(int i = 1;i <= 15;i++){ if(!input[i])  index.push_back(i);}
    //对可能的结果向下递归
    for(int turn = 0;turn < index.size();turn++){
        int temp_empty = index[turn];
        //cout<<temp_empty<<endl;
        for(int i = 1; i <= 15; i++) {   //这里要修改
            bool re[16];
            memcpy(re, input, sizeof(re));    //用于恢复递归前的状态
            if(i < temp_empty) {
                if (i == temp_empty) continue;
                int j = is_ok(i, temp_empty);    //判断是否可以连通，返回是left还是
                if (j) {
                    if (j == 1) {
                        for (int n = 0; n < list[temp_empty].l1; n++) {
                            if (list[temp_empty].left[n] > temp_empty || list[temp_empty].left[n] < i) continue;
                            if(input[list[temp_empty].left[n]] == 0 && list[temp_empty].left[n] != temp_empty){   //遇到空球
                                memcpy(input, re, sizeof(re));   //恢复
                                goto BREAKLOOP;
                            }
                            input[list[temp_empty].left[n]] = 0;
                            input[temp_empty] = 1;
                        }
                    }
                    else if(j == 2){
                        for (int n = 0; n < list[temp_empty].r1; n++) {
                            if (list[temp_empty].right[n] > temp_empty || list[temp_empty].right[n] < i) continue;
                            if(input[list[temp_empty].right[n]] == 0 && list[temp_empty].right[n] != temp_empty){   //遇到空球
                                memcpy(input, re, sizeof(re));   //恢复
                                goto BREAKLOOP;
                            }
                            input[list[temp_empty].right[n]] = 0;
                            input[temp_empty] = 1;
                        }
                    }
                    else{
                        for (int n = 0; n < list[temp_empty].h1; n++) {
                            if (list[temp_empty].hor[n] > temp_empty || list[temp_empty].hor[n] < i) continue;
                            if(input[list[temp_empty].hor[n]] == 0){   //遇到空球
                                memcpy(input, re, sizeof(re));   //恢复
                                goto BREAKLOOP;
                            }
                            input[list[temp_empty].hor[n]] = 0;
                            input[temp_empty] = 1;
                        }
                    }
                }
                else continue;
            }
            else{  //i > temp_empty)
                if (i == temp_empty) continue;
                int j = is_ok(i, temp_empty);    //判断是否可以连通，返回是left还是
                if (j) {
                    if (j == 1) {
                        for (int n = 0; n < list[temp_empty].l1; n++) {
                            if (list[temp_empty].left[n] < temp_empty || list[temp_empty].left[n] > i) continue;
                            if(input[list[temp_empty].left[n]] == 0 && list[temp_empty].left[n] != temp_empty){   //遇到空球
                                memcpy(input, re, sizeof(re));   //恢复
                                goto BREAKLOOP;
                            }
                            input[list[temp_empty].left[n]] = 0;
                            input[temp_empty] = 1;
                        }
                    }
                    else if(j == 2){
                        for (int n = 0; n < list[temp_empty].r1; n++) {
                            if (list[temp_empty].right[n] < temp_empty || list[temp_empty].right[n] > i) continue;
                            if(input[list[temp_empty].right[n]] == 0 && list[temp_empty].right[n] != temp_empty){   //遇到空球
                                memcpy(input, re, sizeof(re));   //恢复
                                goto BREAKLOOP;
                            }
                            input[list[temp_empty].right[n]] = 0;
                            input[temp_empty] = 1;
                        }
                    }
                    else{
                        for (int n = 0; n < list[temp_empty].h1; n++) {
                            if (list[temp_empty].hor[n] < temp_empty || list[temp_empty].hor[n] > i ) continue;
                            if(input[list[temp_empty].hor[n]] == 0 && list[temp_empty].hor[n] != temp_empty){   //遇到空球
                                memcpy(input, re, sizeof(re));   //恢复
                                goto BREAKLOOP;
                            }
                            input[list[temp_empty].hor[n]] = 0;
                            input[temp_empty] = 1;
                        }
                    }
                }
                else continue;
            }
            /*
            for(bool i:input){
                cout<<i<<" ";
            }
            cout<<endl;
             */
            if(!count(input)) {
                ed_num++;
                memcpy(ed[ed_num],input,sizeof(bool[16]));
                string re_s = result;
                int re_n = ed_num;
                result += to_string(i);
                result += " ";
                result += to_string(temp_empty);
                result += "  ";
                if (solution(depth + 1,result)) return true;
                result = re_s;
                ed_num = re_n;
            }
            BREAKLOOP:;
            memcpy(input, re, sizeof(re));   //恢复
        }
    }
    return false;    //要改false
}

int main(){
    cout<<"start"<<endl;
    //cin>>empty;
    empty = 5;  input[empty] = 0;
    for(int i = 1;i <= 11;i++){
        cout<<"step:"<<i<<endl;
        ed_num = -1;
        limit = i;
        if(solution())  break;
    }
    return 0;
}
