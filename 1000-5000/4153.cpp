//AC
//BOJ 4153 직각삼각형
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a = -1, b = -1, c = -1;
    while(1) {
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0)    break;
        if(a*a+b*b == c*c) {
            cout << "right" << "\n";
        }
        else if(a*a+c*c == b*b) {
            cout << "right" << "\n";
        }
        else if(b*b+c*c == a*a) {
            cout << "right" << '\n';
        }
        else    cout << "wrong" << "\n";
    }

    return 0;
}