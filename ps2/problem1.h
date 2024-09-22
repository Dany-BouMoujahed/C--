#include <iostream>
#include <cmath>
using namespace std;
int binarySearch(const int A[], int low, int high, int e){
    if (high - low < 0) {
        return -1;
    }
    int mid = floor((high+low)/2.0);
    if (A[mid] == e){
        return mid;
    }
    else if (A[mid] > e){
        return binarySearch(A, low, (mid-1), e);
    }
    else {
        return binarySearch(A, (mid+1), high, e);
    }
}
int main(){
    int A[] = {1,2,3,4,5,6,7,8,9};
    int b = binarySearch(A, 0, sizeof(A)/sizeof(int), 9);
    cout << b << endl;
}