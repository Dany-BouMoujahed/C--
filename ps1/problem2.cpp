#include <iostream>
#include <string>
using namespace std;

int main(){
    char sex;
    double bw;
    double wrm;
    double wam;
    double hm;
    double fam;
    double a1;
    double a2;
    double a3;
    double a4;
    double a5;
    double b;
    double bodyfat;
    double bodyfatpercent;
    cout << "M or F?: ";
    cin >> sex;
    if (sex == "M"){
        cout << "bw= ";
        cin >> bw;
        cout << "wrm= ";
        cin >> wrm;
        a1 = (bw*1.082)*+94.42;
        a2 = wrm*4.15;
        b = a1-a2;
        bodyfat = bw-b;
        bodyfatpercent = (bodyfat/bw)*100;
    }
    else {
        cout << "bw= ";
        cin >> bw;        
        cout << "wrm= ";
        cin >> wrm;        
        cout << "wam= ";
        cin >> wam;        
        cout << "hm= ";
        cin >> hm;        
        cout << "fam= ";
        cin >> fam;
        a1 = (bw*0.732)+8.987;
        a2 = wrm/3.140;
        a3 = wam*0.157;
        a4 = hm*0.249;
        a5 = fam*0.434;
        b = a1+a2-a3-a4+a5;
        bodyfat=bw-b;
        bodyfatpercent=(bodyfat/bw)*100;
    }
    cout << "body fat = " << bodyfat << endl;
    cout << "body fat % = " << bodyfatpercent << endl; 
    return 0;
}