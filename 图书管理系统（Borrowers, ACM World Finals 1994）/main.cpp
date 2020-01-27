//书本P136
//考察：STL
//QUSTION:图书馆管理系统

//备注：节约时间，没有实现手动输入

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef struct book{
    string name;
    string author;
    book(string a,string b):name(a),author(b){}
    bool operator < (const book& other) const{
        if(author != other.author){
            return (author < other.author);
        }
        return (name < other.name);
    }
};

map <string,int> id; //记录书本原先的位置，检查输入借的书本是否存在
vector <book> borrowed_book;

void borrow(vector <book>& all_book,vector <book>& borrowed_book){
    cout<<"BORROW:\nWhich one do you want to borrow?"<<endl;
    string input;
    cin>>input;
    int count = 0;
    for(book i:all_book){
        if(input == i.name){
            cout<<"DONE!"<<endl;
            borrowed_book.push_back(i);
            all_book.erase(all_book.begin()+count);
            return;
        }
        count++;
    }
    cout<<"CANNOT FIND THE BOOK!"<<endl;
}
void shelve(){
    cout<<"Borrowed Book:"<<endl;
    for(book i:borrowed_book){
        cout<<i.name<<" - "<<i.author<<" -> "<<id[i.name]<<endl;
    }
}
void Return(vector <book>& all_book){
    cout<<"RETURN:\nWhich one do you want to return?"<<endl;
    string input;
    cin>>input;
    int count = 0;
    for(book i:borrowed_book){
        if(input == i.name){
            cout<<"DONE!"<<endl;
            all_book.push_back(i);
            sort(all_book.begin(),all_book.end());
            borrowed_book.erase(borrowed_book.begin()+count);
            return;
        }
        count++;
    }
    cout<<"CANNOT FIND THE BOOK!"<<endl;
}


int main() {
    book a("Test","Tom");   book b("Abc","Alice");  book c("Learn","Bob");
    book d("Cplusplus","Steve");    book e("STL","Bob");    book f("Build","Tom");
    book g("Legend","Ama");
    vector <book> all_book = {a,b,c,d,e,f,g};
    sort(all_book.begin(),all_book.end());
    int count = 0;
    for(book i:all_book){
        id[i.name] = count;
        count++;
    }
    string option;
    while(cin>>option && option != "END") {
        if (option == "BORROW") {
            borrow(all_book,borrowed_book);
        }
        else if(option == "SHELVE"){
            shelve();
        }
        else if(option == "traverse"){
            for(book i:all_book){
                cout<<i.name<<" - "<<i.author<<endl;
            }
        }
        else if(option == "RETURN"){
            Return(all_book);
        }
    }
    return 0;
}