//AC
//BOJ 17305 사탕배달
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
vector<ll> five;
vector<ll> three;
vector<ll> five_sum;
vector<ll> three_sum;
bool cmp (const ll &a, const ll &b) {
    return a > b;
}
ll l_max(ll a, ll b) {
    return a > b ? a : b;
}
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int N, W;
    cin >> N >> W;
    five_sum.resize(N+1);
    three_sum.resize(N+1);
    for(int i=0; i<N; i++) {
        int t, s;
        cin >> t >> s;
        if(t==3)    three.push_back(s);
        else    five.push_back(s);
    }
    sort(three.begin(), three.end(), cmp);
    sort(five.begin(), five.end(), cmp);
    for(int i=1; i<= three.size(); i++) {
        three_sum[i] = three_sum[i-1] + three[i-1];
    }
    for(int i=1; i<=five.size(); i++) {
        five_sum[i] = five_sum[i-1] + five[i-1];
    }
    int cnt3 = three.size();
    int cnt5 = five.size();
    ll ans = 0;
    int minCnt = min(W/3, cnt3);
    while(minCnt >= 0) {
        int minCnt5 = min((W-((minCnt)*3))/5, cnt5);
        ans = l_max(ans, three_sum[minCnt] + five_sum[minCnt5]);
        minCnt -= 1;
    }
    cout << ans;
    return 0;
}