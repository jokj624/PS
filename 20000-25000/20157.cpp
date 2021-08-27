//AC
//BOJ 20157 화살을 쏘자
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
map<pii, int> ans;
int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, res = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 0) {
            y /= abs(y);
            ans[{0, y}] += 1;
            continue;
        }
        else if(y == 0) {
            x /= abs(x);
            ans[{x, 0}] += 1;
            continue;
        }
        int g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        ans[{x, y}] += 1;
    }
    for(auto tmp : ans) {
        res = max(res, tmp.second);
    }
    cout << res;
    return 0;
}