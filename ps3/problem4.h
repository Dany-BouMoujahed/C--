#include <iostream>
#include <vector>
using namespace std; 
struct dateT {int day , month , year;
    dateT(int d, int m, int y){
        day=d;
        month=m;
        year=y;
    }
    dateT(){
        day=1;
        month = 1;
        year = 2024;
    }

    friend ostream& operator <<(ostream & o, dateT &d){
        o << d.day << "/" << d.month << "/" <<d.year;
        return o;
    }
};
struct itemT { string name ; int price ; dateT expiry ; unsigned int available ;
    itemT(string n,int p, dateT e, unsigned int a){
        name= n;
        price=p;
        expiry=e;
        available =a;
    }
    friend ostream& operator<<(ostream &o, itemT & i){
        o << i.name << " " << i.price << " " << i.expiry <<" " <<i.available << endl;
        return o;
    }
};
struct billT {unsigned int value ; string unit;
    billT(unsigned int v, string u){
        value =v;
        unit=u;
    }
    billT(){
        value = 10;
        unit = "USD";
    }
    friend ostream & operator <<(ostream & o, billT & b){
        o << b.value << " " << b.unit;
        return o;
    }
};
struct basketT { vector < itemT > items ; 
    basketT(vector <itemT> i){
        items = i;
    }
    basketT(){
        vector<itemT> i;
        items=i;
    }
    friend ostream& operator <<(ostream & o, basketT & b){
        if (b.items.size() == 0){
         o << "Empty Basket"<<endl;
         return o;
        }
        else{
            for (int i = 0; i < b.items.size(); i++)
            {
                o << b.items.at(i);
            }
            return o;
        }
    }
    void addItem(itemT i){
        items.push_back(i);
    } 
    int getTotal(){
        int t=0;
        for (int i = 0; i <items.size(); i++)
            {
                t+= items.at(i).price;
            }
        return t;    
    }  
};

struct customerT { basketT b; billT cash;
    customerT(basketT bb,billT c){
        b= bb;
        cash=c;
    }
    void addToBasket(itemT item){
        b.addItem(item);
    }
    friend ostream & operator <<(ostream& o, customerT & c){
        o << c.b << c.cash.value<<" "<<c.cash.unit<<endl;
        return o;
    }
};
struct registerT { vector < billT > bills ; vector <unsigned int> count; vector <customerT>customers;
    registerT(){
        vector<billT> b;
        bills=b;
        vector<unsigned int> c;
        count=c;
        vector<customerT> cu;
        customers=cu;
    }
    friend ostream& operator <<(ostream& o, registerT & r){
        if (r.customers.size()==0 && r.bills.size()==0){
            o << "Empty Register"<<endl;
            return o;
        }
        else{
            for (int i = 0; i < r.bills.size(); i++)
            {
                o << r.bills.at(i).value << " " << r.bills.at(i).unit <<" " << r.count.at(i)<< endl;
            }
            for (int i = 0; i < r.customers.size(); i++)
            {
                o <<r.customers.at(i)<<endl;
            }
           return o; 
        }
    }
    void addCustomer(customerT c){
        customers.push_back(c);
    }
    void addBills(billT b, unsigned int c){
        bool exists =false;
            for (int i=0; i < bills.size(); i++){
            if (bills[i].value == b.value){
                count[i] = count[i] + c;
                exists = true;
                break;
                }
            }
            if (!exists){
                count.push_back(c);
                bills.push_back(b);
            }
            for (int i = 0; i < bills.size() - 1; i++){
                for (int j = i+1; j < bills.size(); j++){
                    if (bills[j].value < bills[i].value){
                        swap(count[i], count[j]);
                        swap(bills[i], bills[j]);
                    }
                }
            }
        }
    bool handleCustomer(customerT & c){
        int change = (c.cash.value-c.b.getTotal());
        if(change>= 0){
            addBills(c.cash, 1);
            for (int i = bills.size()-1; i >= 0; i--)
            {
                unsigned int num=change/bills[i].value;
                if(count[i]<num){
                    num=count[i];
                }
                count[i]-=num;
                change-=num*bills[i].value;
                if(change==0){
                    break;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
};