#include <iostream>
using namespace std;
void swap (int & x, int & y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int list[] = {1,2,3,4,5,6};
    swap(list[2],list[3]);
    swap(list[3],list[5]);
    for (int i = 0; i < 6; i++)
    {
        cout << list[i] << endl;
    }
    
    return 0;
}

