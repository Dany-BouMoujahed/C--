#include <iostream>
using namespace std;
int main (){
    cout << "hello bitches!" << endl;
    while (true){
    int n;
    int s;
    cout << "enter an integer: ";
    cin >> n;
    if (n == -1){
        break;
    }
    cout << "enter a step size: ";
    cin >> s;
    if (s == -1){
        break;
    }
    else if (s < 0 || n < 0){
        cout << "Error! Input integer must be non-negative" << endl;
    }
    else if (s == 0){
        cout << "Error! step cant be zero" << endl;
    }
    else {
        int i = 0;
        while (s*i < n){
            cout << s*i << " ";
            i++;
        }
        cout << endl;
    }
    }
    cout << "au revoir" << endl;
    return 0;
}