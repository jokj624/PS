//AC
//BOJ 2470 두 용액
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9+1
using namespace std;
typedef long long ll;
vector<int> v;
int main(){
	int N, tmp;
	int ans1, ans2;
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	ll sum = INF;
	for(int i=0; i<N; i++){
		int idx = lower_bound(v.begin(), v.end(), -v[i])-v.begin();
		for(int j = idx; j >= idx-1; j--){
			if(j < 0 || j >= N || i == j)	continue;
			if(sum > abs(v[i]+v[j])){
				sum = abs(v[i]+v[j]);
				ans1 = v[i];
				ans2 = v[j];
			}
		}
	}
	if(ans1 > ans2)	cout << ans2 << " " << ans1;
	else	cout << ans1 << " " << ans2;
	return 0;
}
