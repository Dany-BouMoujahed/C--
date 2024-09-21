#include <iostream>
#include <cmath>
using namespace std;
int main() { 
    int order;
    int i;
    double series=0;
    double estimation;
    double error;
    cout << "enter an order: ";
    cin >> order;
    if (order>=0) {
            for (i=0; i <= order; i++) {
            series = (pow(-1,i)/(2*i+1))+series;
            error = 4*pow(-1,i)/(2*i+1);
    }
    estimation = 4*series;
    cout << estimation << endl;
    cout << error << endl;
    }
    else {
        cout << "order can't be negative";
    }
    return 0;
}