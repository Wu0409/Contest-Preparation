//书本P137
//考察：STL
//QUSETION:交易所，模拟订单处理系统 https://vjudge.net/problem/UVA-1598

//如果有订单有余，如200 36 -》100 36 / 50 36 只会处理第一笔订单

#include <iostream>
#include <queue>

# define Max_price 99999
# define Min_price 0

using namespace std;

typedef struct info{
    int num;
    int price;
    int time;
    bool operator <(const info& b) const{
        if(price == b.price) {
            return time < b.time;
        }
        return (price < b.price);
    }
};

vector <info> buyer;
vector <info> seller;
int Time = 1;

void update_buyer(){
    cout<<"Input the number and price perspectively:"<<endl;
    info temp;
    cin>>temp.num>>temp.price;
    temp.time = Time;
    if(!seller.empty()){
        if(seller[0].price <= temp.price){
            if(seller[0].num > temp.num){
                seller[0].num -= temp.num;
                cout<<"TRADE "<<temp.num<<" "<<seller[0].price<<endl;
                return;
            }
            else if(seller[0].num < temp.num){
                temp.num -= seller[0].num;
                cout<<"TRADE "<<seller[0].num<<" "<<seller[0].price<<endl;
                seller.erase(seller.begin());
            }
            else{
                cout<<"TRADE "<<seller[0].num<<" "<<seller[0].price<<endl;
                seller.erase(seller.begin());
                return;
            }
        }
    }
    buyer.push_back(temp);
    sort(buyer.begin(),buyer.end());
}

void update_seller(){
    cout<<"Input the number and price perspectively:"<<endl;
    info temp;
    cin>>temp.num>>temp.price;
    temp.time = Time;
    if(!buyer.empty()){
        if(buyer[buyer.size() - 1].price >= temp.price){
            if(buyer[buyer.size() - 1].num > temp.num){
                buyer[buyer.size() - 1].num -= temp.num;
                cout<<"TRADE "<<temp.num<<" "<<buyer[buyer.size() - 1].price<<endl;
                return;
            }
            else if(buyer[buyer.size() - 1].num < temp.num){
                temp.num -= buyer[buyer.size() - 1].num;
                cout<<"TRADE "<<buyer[buyer.size() - 1].num<<" "<<buyer[buyer.size() - 1].price<<endl;
                seller.pop_back();  //应该是相同最高价的第一笔，不是最后一个
            }
            else{
                cout<<"TRADE "<<buyer[buyer.size() - 1].num<<" "<<buyer[buyer.size() - 1].price<<endl;
                seller.pop_back();  //应该是相同最高价的第一笔，不是最后一个
                return;
            }
        }
    }
    seller.push_back(temp);
    sort(seller.begin(),seller.end());
}

void cancel(){
    int target;
    cout<<"Input the cancel order:"<<endl;
    cin>>target;

    for(int i = 0;(i <= buyer.size() - 1) && (!buyer.empty());i++){
        if(buyer[i].time == target){
            buyer.erase(buyer.begin() + i + 1);
            return;
        }
    }
    for(int i = 0;(i <= seller.size() - 1) && (!seller.empty());i++){
        if(seller[i].time == target){
            seller.erase(seller.begin() + i + 1);
            return;
        }
    }
}
int main() {
    string option;
    while(cin>>option && option != "END"){
        //更新交易信息
        if(option == "BUY"){
            Time++;
            update_buyer();
        }
        else if(option == "SELL"){
            Time++;
            update_seller();
        }
        else if(option == "CANCEL"){
            cancel();
        }

        //输出交易情况
        int sum_buyer_min = 0;
        int sum_seller_min = 0;
        for(int i = 0;i < buyer.size() && buyer[i].price == buyer[0].price;i++){
            sum_buyer_min += buyer[i].num;
        }
        for(int i = 0;i < seller.size() && seller[i].price == seller[0].price;i++){
            sum_seller_min += seller[i].num;
        }

        if(buyer.size() != 0 && seller.size() != 0){
            cout<<"QUOTE "<<sum_buyer_min<<" "<<buyer[0].price<<" - "<<sum_seller_min<<" "<<seller[0].price<<endl;
        }
        else if(buyer.size() == 0 && seller.size() != 0){
            cout<<"QUOTE "<<"0"<<" "<<Min_price<<" - "<<sum_seller_min<<" "<<seller[0].price<<endl;
        }
        else if(buyer.size() != 0 && seller.size() == 0){
            cout<<"QUOTE "<<sum_buyer_min<<" "<<buyer[0].price<<" - "<<"0"<<" "<<Max_price<<endl;
        }
        else{
            cout<<"QUOTE "<<"0"<<" "<<Min_price<<" - "<<"0"<<" "<<Max_price<<endl;
        }
    }
    return 0;
}