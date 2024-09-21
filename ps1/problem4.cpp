#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int foods;
    int drinks;
    int friends;
    int tbeforetip;
    double tip;
    double total;
    double roundedshare;
    cout << "price of food: ";
    cin >> foods;
    cout << "price of drinks: ";
    cin >> drinks;
    cout << "number of friends: ";
    cin >> friends;
    tbeforetip = foods + drinks;
    tip = tbeforetip*0.15;
    total= tip + tbeforetip;
    roundedshare = ceil((total/friends)/1000)*100;
    cout << "Rounded Share = " << roundedshare << endl;
    return 0; 
}