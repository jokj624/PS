//AC
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int dis = abs(a-b);
        int N = dis * 2;
        if(a > N || b > N || c > N) {
            cout << "-1\n";
            continue;
        }
        if(c+dis <= N) {
            if(c+dis != a && c+dis != b) {
                cout << c+dis << "\n";
                continue;
            }
        }
        int dif;
        if(c > dis)     dif = c-dis;
        else    dif = dis - c;
        if(dif <= N) {
            if(dif != a && dif != b) {
                cout << dif << "\n";
            }
            else     cout << "-1\n";
        } 
    }
    return 0;
}