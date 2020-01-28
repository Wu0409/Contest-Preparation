//书本P148
//考察：二叉树
//QUESTION:小球下落

#include <iostream>
#include <cmath>
using namespace std;

int min_num,max_num,result;

typedef struct treenode{
    int number,Switch;
    treenode* l_child,* r_child;
    treenode(){
        Switch = 0; l_child = NULL;  r_child = NULL;
    }
};

void create (treenode* &root,int n){
    root = new treenode;
    root->number = n;
    if(root->number >= min_num && root->number <= max_num){ //最低层叶子节点
        return;
    }
    create(root->l_child,2 * n);
    create(root->r_child,2 * n + 1);
}

void route(treenode*& root,int num){
    if(root->l_child == NULL && root->r_child == NULL){ //到达底部（叶子节点）
        root->Switch *= -1; //开关切换
        result = num;
        return;
    }
    if(root->Switch == 0){
        root->Switch = 1;   //开关切换
        route(root->l_child,2 * num);
    }
    else{
        root->Switch = 0;   //开关切换
        route(root->r_child,2 * num + 1);
    }
}

int main(){
    int depth,number;
    cin>>depth>>number;
    min_num = pow(2,(depth - 1));
    max_num = pow(2,depth) - 1;
    treenode* root;
    create(root,1);
    for(int i = 1;i <= number;i++){
        route(root,1);
    }
    cout<<result<<endl;
}