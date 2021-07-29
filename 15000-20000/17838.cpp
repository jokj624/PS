//AC
//BOJ 17838 커맨드
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        if(str.size() != 7) {
            cout << 0 << "\n";
        }
        else {
            char one = str[0];
            char two = str[2];
            if(one == two) {
                cout << 0 << "\n";
            }
            else { 
                string s;
                s.push_back(one);
                s.push_back(one);
                s.push_back(two);
                s.push_back(two);
                s.push_back(one);
                s.push_back(two);
                s.push_back(two);
                if(s == str)    cout << 1 << "\n";
                else    cout << 0 << "\n";
            }
        } 
    }

    return 0;
}