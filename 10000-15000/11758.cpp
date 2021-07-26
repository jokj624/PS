//AC
//BOJ 11758 CCW
#include <iostream>
using namespace std;
int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
    int a = x1*y2 + x2*y3 + x3*y1;
    int b = x3*y2 + x2*y1 + x1*y3;
    return a-b;
}
int main() {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int D =  ccw(x1,x2,x3,y1,y2,y3);
    if (D < 0)  cout << "-1";
    else if (D > 0)  cout << "1";
    else    cout << "0";
    return 0;
}