#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a;
    double b;
    double c;
    double delta;
    double root1;
    double root2;
    cout<<"a= ";
    cin>>a;
    cout<<"b= ";
    cin>>b;
    cout<<"c= ";
    cin>>c;
    delta=(pow(b,2)) - (4*a*c);  
    if (delta >= 0) {
        root1=(-b-pow(delta,0.5))/(2*a);
        root2=(-b+pow(delta,0.5))/(2*a);
        cout<<"The equation has two roots: " << root1 << " and "<< root2 <<endl;
    }  
    else if  (delta==0) {
        root1=-(b/(2*a));
        cout<<"The equation has one root: "<<root1;
    }
    else {
        cout<<"The equation has no roots"<<endl;       
        } 
    return 0; 
    }
     