//AC
//BOJ 8201 Pilots
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;
deque<pair<ll, ll> > maxd;
deque<pair<ll, ll> > mind;
ll max_l(ll a, ll b){
	return a >= b ? a : b;
}
vector<int> arr;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, num, ck = 0;
	ll t, gap = 0, ans = 0;
	cin >> t >> n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
		if(i!=0 && arr[i] != arr[i-1])	ck = 1;
	}
	for(int i=1; i<=n; i++){
		num = arr[i-1];
		while(!maxd.empty() && maxd.back().first <= num){
			maxd.pop_back();
		} 
		while(!mind.empty() && mind.back().first >= num){
			mind.pop_back();
		}
		maxd.push_back({num, i});
		mind.push_back({num, i});
		while(maxd.front().first - mind.front().first > t){
			if(maxd.front().second > mind.front().second){
				gap = mind.front().second;
				mind.pop_front();	
			}
			else{
				gap =  maxd.front().second;
				maxd.pop_front(); 
			}
		}
		ans = max_l(ans, i - gap);
		
	}
	if(!ck)	cout << n;
	else	cout << ans;
//	cout << ans;
	return 0;
} 