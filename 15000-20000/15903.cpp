//AC
//BOJ 15903 카드 합체 놀이
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;
priority_queue<ll, vector<ll>, greater<ll> > card;
int main(){
	int n, m, tmp;
	ll fir, sec, ans = 0, sum = 0;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		card.push(tmp);
	}
	while(m--){
		fir = card.top();
		card.pop();
		sec = card.top();
		card.pop();
		sum = fir+sec;
		card.push(sum);
		card.push(sum);
	}
	while(!card.empty()){
		ans += card.top();
		card.pop();
	}
	cout << ans;
	return 0;
}