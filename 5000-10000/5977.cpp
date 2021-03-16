////AC
//BOJ 5977 Mowing the Lawn
#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;
ll E[101010];
ll dp[101010];
deque<pair<ll, ll> > d;
ll max_l(ll a, ll b){
	return a >= b ? a : b;
}
int main(){
	int N, K, idx, prev=0;
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		cin >> prev;
		E[i] = E[i-1] + prev; //합
	}
	d.push_back({0, 0});
	for(int i=1; i<=N; i++){
		//고르지 않는 소 ?
		while(!d.empty() && d.front().second < i-K){
			d.pop_front();
		}  
		dp[i] = E[i] + d.front().first;   //E[i] - E[j] + dp[j-1]
		while(!d.empty() && d.back().first < dp[i-1]-E[i]){
			d.pop_back();
		}

		d.push_back({dp[i-1]-E[i], i});  //dp[j-1]-E[j] 관리
		dp[i] = max_l(dp[i-1], dp[i]);
	}
	cout << dp[N];
	return 0;
}