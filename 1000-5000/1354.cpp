//AC
//BOJ 1354 무한 수열 2
#include <iostream> 
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
ll N, P, Q, X, Y;
map<ll, ll> m;
ll makeMap(ll n) {
    if(n <= 0)  return 1;
    if(m[n]) {
        return m[n];
    }
    return m[n] = makeMap(n/P-X) + makeMap(n/Q-Y);
}
int main() {
    cin >> N >> P >> Q >> X >> Y;
    cout << makeMap(N);
}