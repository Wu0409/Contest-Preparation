//书本P218
//QUESTION：最大的数 https://onlinejudge.org/external/118/11882.pdf

//备注：样例输入
#include <iostream>
#include <vector>
using namespace std;

char Map[3][7] = {{'#','#','9','7','8','4','#'},
                  {'#','#','1','2','3','#','#'},
                  {'#','#','4','5','#','#','#'},};
vector <int> ans;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool is_ok(int r,int c){
    return (r >= 0 && c >= 0 && r <= 2 && c <= 6 && Map[r][c] != '#');
}

bool count(bool used[3][7],int r,int c){   //是否走过
    return used[r][c];
}

void solution(int start_r,int start_c,const string& result,bool used[3][7]){
    bool is_end = true;
    for(int i = 0;i < 4;i++){
        if(is_ok(start_r + dr[i],start_c + dc[i])){ //可以走
            string temp_result = result;
            temp_result += Map[start_r + dr[i]][start_c + dc[i]];
            if(!count(used,start_r + dr[i],start_c + dc[i])){
                bool temp_used[3][7];   memcpy(temp_used,used,sizeof(temp_used));
                temp_used[start_r + dr[i]][start_c + dc[i]] = true;
                is_end = false;
                solution(start_r + dr[i],start_c + dc[i],temp_result,temp_used);
            }
        }
    }
    if(is_end) {
        int temp_ans = stoi(result);
        ans.push_back(temp_ans);
    }
}

int main() {
    for(int i = 0;i <= 2;i++){
        for(int j = 0;j <= 6;j++){
            if(Map[i][j] != '#') {
                bool start[3][7];
                memset(start, false, sizeof(bool[3][7]));
                start[i][j] = true;
                string temp;    temp += Map[i][j];
                solution(0, 3, temp, start);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<"result: "<<*(ans.end()-1)<<endl;
    return 0;
}
