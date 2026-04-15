#include <iostream>
#include <iomanip>
using namespace std;

void MyTime::print() {
    cout << setfill('0') << setw(2) << hours << ":"
         << setw(2) << minutes << ":"
         << setw(2) << seconds << ":"
         << setw(3) << milliseconds << endl;
}