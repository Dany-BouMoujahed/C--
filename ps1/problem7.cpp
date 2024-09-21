#include <iostream>
using namespace std;
int main () {
    int n;
    int buffer;
    int max;
    cin>>n;
    if (n==0) {
        cout <<"Empty sequence";
    }
    else if (n>0) { 
        cout << "Int 0= " << endl;
        cin >> max;
        for (int i=1; i<n; i++) {
            cout << "Int " << i << "=" << endl;
            cin >> buffer;
            if (max<buffer){
                max=buffer;
                }
        cout<<"Max= "<<max<<endl;
    } 
    }
    else {
        cout<<"size cant be negative";
    }
    return 0;
    }