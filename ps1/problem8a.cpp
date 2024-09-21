#include <iostream>
using namespace std; 
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
  if (i!=j) {
    cout<<"Sequences are not equal"<<endl; 
    return 0;
  }
  while (k<i) {
    if (sequence1[k] != sequence2[k]) {
      cout << "Sequences are not equal" << endl; 
      return 0;
    }
    k++;
  }
  cout << "Sequences are equal" << endl; 
  return 0; 
