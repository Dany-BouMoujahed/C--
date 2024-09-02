#include <iostream>
#include <string>
using namespace std;

int main(){
    string sex;
    double bw;
    double wrm;
    double wam;
    double hm;
    double fam;
    double a1;
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
    }
    return 0;
}