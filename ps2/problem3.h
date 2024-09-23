#include <iostream>
using namespace std;
class Array
{
private:
    int Storage[1024];
    int n;
public:
    Array(){
        n=0;
    }
    Array (Array & a){
        n = a.n;
        for (int i = 0; i < a.n;i++){
            Storage[i] = a.Storage[i];
        }
    }
    bool addElement(int e){
        if (n<1024){
            Storage[n-1]=e;
            return true;
        }
        else {
            cout << "Maximum Storage reached" << endl;
            return false;
        }
    }
    Array & operator=(Array & oa){
        n = oa.n;
        for (int i = 0; i < oa.n; i++){
            Storage[i] = oa.Storage[i];
        }
        return *this;
    }
    friend ostream & operator << (ostream & ostr, Array & arr);
};
ostream & operator << (ostream & ostr, Array & arr){
    for (int i = 0; i < arr.n; i++){
        ostr << arr.Storage[i] << " ";
    }
    return ostr;
}

