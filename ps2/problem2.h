#include <iostream>
#include <cmath>
using namespace std;
int binarySearch(const int A[], int low, int high, int e){
    int mid = (high+low)/2;
    if ((high - low) >= 4){
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
    else
    {
        for (int i = 0; i < high; i++){
            if (A[i] == e){
                return i;
            }
        }
        return -1;
    }
    
}