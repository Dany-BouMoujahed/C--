#include <iostream>
using namespace std;
int main() {
    int seconds;  
    int minutes;
    int hours;
    cout<< "Time (in seconds):";
    cin >> seconds;
    hours = seconds/3600;
    minutes = (seconds%3600)/60;
    seconds = seconds%60;
    cout << hours << ":" << minutes << ":" <<seconds << endl;
    return 0;
}