#include <iostream>
using namespace std;
int main() {
double x;
cout << "Name: x" << endl;
cout << "Type: int" << endl;
cout << "Size: " << sizeof(x) << endl;
cout << "Address: " << &x << endl;
cout << "Initial value: " << x << endl; // this will be some random value in memory
x = -123.24;//Store 1024 in x
cout << "Assigned value: " << x << endl;
x = x + 2; //Add 2 to the value in x and store the result in x.
cout << "Incremented value: " << x << endl;
return 0;
}