//书本P177
//考察：二叉树
//QUESTION：二叉树的重建

#include <iostream>
using namespace std;
typedef struct node{
    char data;
    node* l_child;
    node* r_child;
    node(char in = '#'):data(in),l_child(NULL),r_child(NULL){}
};

string pre,mid; //前序，中序
int i = 0;
void solve(node* &root,int left,int right){   //index是根节点的位置
    if(left > right) return;
    root = new node(pre[i]);
    int pivotal = mid.find(pre[i]);
    i++;
    if(left == right){
        return;
    }
    solve(root->l_child, left, pivotal - 1);
    solve(root->r_child, pivotal + 1, right);
}

void output(node* &root){
    if(root == NULL){
        return;
    }
    output(root->l_child);
    output(root->r_child);
    cout<<root->data;
}

int main() {
    //样例输入
    pre = "DBACEGF";    mid = "ABCDEFG";
    node* root;
    solve(root,0,pre.length() - 1);
    output(root);
    return 0;
}