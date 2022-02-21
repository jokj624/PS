//AC
//BOJ 23320 홍익 절대평가
#include <iostream>
#include <algorithm>
using namespace std;
int student[101];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> student[i];
    }
    int x, y;
    cin >> x >> y;
    int count = x * n;
    count /= 100;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(student[i] >= y) {
            ans += 1;
        }
    }
    cout << count << " " << ans;
    return 0;
}