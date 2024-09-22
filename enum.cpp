#include <iostream>
using namespace std;

int main(){
enum ColorEm { RED , GREEN , BLUE };
enum DayEm { MON , TUES , WED , THUR , FRI , SAT , SUN };
ColorEm c = BLUE ;
cout << c << endl;
int c2 = GREEN ;
cout << c2 << endl;
DayEm d = MON ;
cout << d << endl;
int d2 = MON ;
cout << d2 << endl;
d2++;
cout << d2 << endl;
return 0;
}