//AC
//BOJ 1259 팰린드롬 수
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(1) {
        string s, r_s;
        cin >> s;
        if(s == "0")    break;
        r_s = s;
        reverse(r_s.begin(), r_s.end());
        if(s == r_s)    cout << "yes" << '\n';
        else cout << "no" << "\n";
    }
    return 0;
}