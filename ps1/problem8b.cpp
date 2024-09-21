#include <iostream>
using namespace std;
 void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
  int sequence1[1024];
  int sequence2[1024];
  int i;
  int j;
  int k=0; 
  cout << "Enter the  integers in the first sequence separated by spaces: "<<endl;  
  for(i = 0; i < 1024; i++) {
    cout << "Int "<<i<<"= "<<endl;
    cin >> sequence1[i];
    if (sequence1[i]==-1){
      break;
    } 
  }
  cout << "Enter the  integers in the second sequence separated by spaces: "<<endl;  
  for(j = 0; j < 1024; j++) {
    cin >> sequence2[j];
    if (sequence2[j] == -1) {
      break;
    }
  }
  bubbleSort(sequence1,i);
  bubbleSort(sequence2,j);
    bool arePermutations = true;
    for (int l = 0; l < i; l++) {
        if (sequence1[l] != sequence2[l]) {
            arePermutations = false;
            break;
        }
    }
    if (arePermutations) {
        cout << "Yes: second sequence is a permutation of the first" << endl;
    } else {
        cout << "NO: second sequence is not a permutation of the first" << endl;
    }

  return 0; 
}
