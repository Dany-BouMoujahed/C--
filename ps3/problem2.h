#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;
const int ORIGINAL_CAPACITY = 16;
const int GROW_FACTOR = 2;

struct DynArr {
    int * data ;
    unsigned int size , capacity ;
    DynArr () : size (0) , capacity (ORIGINAL_CAPACITY){ // preallocate memory
    data = new int [capacity];
    }
    void insert (int t) {
        if ( size >= capacity ) { // grow the array
        unsigned int newcapacity = capacity * GROW_FACTOR ;
        int * newdata = new int [ newcapacity ];
        for ( int i =0; i < size ; i ++) {
            newdata [ i ] = data [ i ]; // copy old data
        }
        delete [] data ; // discard old memory
        data = newdata ; // point to the new data
        capacity = newcapacity ; // set capacity
        }
    data [ size ] = t ; // place new element
    size = size + 1; // increment size
    }
    void insertSlow (int t) {
        if ( size >= capacity ) { // grow the array
        unsigned int newcapacity = capacity + 10 ;
        int * newdata = new int [ newcapacity ];
        for ( int i =0; i < size ; i ++) {
            newdata [ i ] = data [ i ]; // copy old data
        }
        delete [] data ; // discard old memory
        data = newdata ; // point to the new data
        capacity = newcapacity ; // set capacity
        }
    data [ size ] = t ; // place new element
    size = size + 1; // increment size
    }
};
int main(){
    DynArr A;
    clock_t c_start = clock ();
    for (int i = 0; i < 1000; i++){
        A.insert(i);
    }
    clock_t c_end = clock();
    double elapsed = 1000.0*(c_end - c_start)/CLOCKS_PER_SEC;
    cout << fixed<<setprecision(2)<<"CPU time used: "<< elapsed << " ms" << endl;
    vector<int> v;
    clock_t c_start = clock ();
    for (int i = 0; i < 1000; i++){
        v.push_back(i);
    }
    clock_t c_end = clock();
    cout << v.at(1000);
    double elapsed = 1000.0*(c_end - c_start)/CLOCKS_PER_SEC;
    cout << fixed<<setprecision(2)<<"CPU time used: "<< elapsed << " ms" << endl;
    return 0;
}