//AC
//BOJ 2180 소방서의 고민 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	return (a.first*b.second) > (a.second*b.first);
}
int main(){
	int n, a, b, ans = 0
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0)	continue;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<v.size(); i++){
		pair<int, int> tmp = v[i];
		ans += (tmp.first*ans + tmp.second);
		ans %= 40000;
	}
	cout << ans;
	return 0;
}
