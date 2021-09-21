//AC
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int alpha[27] = {0, };
        int ans = 0;
        for(int i=0; i<str.size(); i++) {
            alpha[str[i]-'a']++;
        }
        for(int i=0; i<27; i++) {
            if(alpha[i] >= 2)   ans += 2;
            else    ans += alpha[i];
        }
        cout << ans / 2 << "\n";
    }

    return 0;
}