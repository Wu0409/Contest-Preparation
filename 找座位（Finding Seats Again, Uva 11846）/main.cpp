//书本：P218
//QUESTION：找座位 https://onlinejudge.org/external/118/11846.pdf
//样例输入

#include <iostream>
#include <vector>

using namespace std;
typedef struct axis{
    int r,c;
    axis(int r1,int c1):r(r1),c(c1){}
};

vector <axis> p;
char c[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
char input[7][7] = {{'.','.','.','4','.','2','.'},
                    {'.','.','.','4','5','.','.'},
                    {'2','2','2','.','.','3','.'},
                    {'.','.','.','2','.','.','3'},
                    {'.','2','4','.','.','.','2'},
                    {'.','.','.','2','.','3','.'},
                    {'2','2','.','.','3','.','.'}};

void solution(int index,char st[7][7]){
    char cc = c[index];
    if(index >= p.size()){
        for(int i = 0;i < 7;i++){
            for(int j = 0;j < 7;j++){
                cout<<st[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    int r = p[index].r; int c = p[index].c;
    st[r][c] = cc;
    //左右
    int w_max = 0,e_max = 0;
    while(input[r][c - (w_max + 1)] == '.'  && c - (w_max + 1) >= 0 && st[r][c - (w_max + 1)] == '.'){   w_max++;}
    while(input[r][c + (e_max + 1)] == '.'  && c + (e_max + 1) <= 6 && st[r][c + (e_max + 1)] == '.'){   e_max++;}
    int sum = (int(input[r][c]) - 48) - 1;
    if(w_max >= e_max){
        for(int i = 0;i <= w_max && i <= sum;i++){
            bool ok = true;
            if(sum - i > e_max || i > sum) continue;
            char temp_st[7][7]; memcpy(temp_st,st,sizeof(temp_st));
            for(int j = 1;j <= i;j++){
                if(temp_st[r][c - j] == '.'){
                    temp_st[r][c - j] = cc;
                }
                else{ ok = false;}
            }
            for(int k = 1;k <= sum - i;k++){
                if(temp_st[r][c + k] == '.') {
                    temp_st[r][c + k] = cc;
                }
                else{ ok = false;}
            }
            if(ok)  solution(index + 1,temp_st);
        }
    }
    else{   //w_max >= s_max
        for(int i = 0;i <= e_max && i <= sum;i++){
            bool ok = true;
            if(sum - i > w_max || i > sum) continue;
            char temp_st[7][7]; memcpy(temp_st,st,sizeof(temp_st));
            for(int j = 1;j <= i;j++){
                if(temp_st[r][c + j] == '.'){
                    temp_st[r][c + j] = cc;
                }
                else{ ok = false;}
            }
            for(int k = 1;k <= sum - i;k++){
                if(temp_st[r][c - k] == '.') {
                    temp_st[r][c - k] = cc;
                }
                else{ ok = false;}
            }
            if(ok)  solution(index + 1,temp_st);
        }
    }
    //上下
    int n_max = 0,s_max = 0;
    while(input[r - (n_max + 1)][c] == '.'  && r - (n_max + 1) >= 0 && st[r - (n_max + 1)][c] == '.'){   n_max++;}
    while(input[r + (s_max + 1)][c] == '.'  && r + (s_max + 1) <= 6 && st[r + (s_max + 1)][c] == '.'){   s_max++;}
    int sum1 = (int(input[r][c]) - 48) - 1;
    if(n_max >= s_max){
        for(int i = 0;i <= n_max && i <= sum1;i++){
            bool ok = true;
            if(sum1 - i > s_max || i > sum1) continue;
            char temp_st[7][7]; memcpy(temp_st,st,sizeof(temp_st));
            for(int j = 1;j <= i;j++){
                if(temp_st[r-j][c] == '.') {
                    temp_st[r - j][c] = cc;
                }
                else{ ok = false;}
            }
            for(int k = 1;k <= sum1 - i;k++){
                if(temp_st[r+k][c] == '.') {
                    temp_st[r + k][c] = cc;
                }
                else{ ok = false;}
            }
            if(ok)  solution(index + 1,temp_st);
        }
    }
    else{   //n_max < s_max
        for(int i = 0;i <= s_max && i <= sum1;i++){
            bool ok = true;
            if(sum1 - i > n_max || i > sum1) continue;
            char temp_st[7][7]; memcpy(temp_st,st,sizeof(temp_st));
            for(int j = 1;j <= i;j++){
                if(temp_st[r+j][c] == '.') {
                    temp_st[r + j][c] = cc;
                }
                else{ ok = false;}
            }
            for(int k = 1;k <= sum1 - i;k++){
                if(temp_st[r-k][c] == '.') {
                    temp_st[r - k][c] = cc;
                }
                else{ ok = false;}
            }
            if(ok)  solution(index + 1,temp_st);
        }
    }
}

void init(){
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
             if(input[i][j] != '.'){
                 axis temp(i,j);
                 p.push_back(temp);
             }
        }
    }
}
int main() {
    cout<<"start"<<endl;
    init();
    char temp[7][7];
    memset(temp,'.',sizeof(char[7][7]));
    solution(0,temp);
    return 0;
}
