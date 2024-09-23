using namespace std;
int binarySearch(const int A[], int low, int high, int e){
    int mid = (high+low)/2;
    if (low > high) {
        return -1;
    }
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