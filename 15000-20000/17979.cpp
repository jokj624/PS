//AC
//BOJ 17979 What's Mine is Mine
//https://www.acmicpc.net/problem/17979
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int t[101];
vector<pair<int, int> > a[15001];
int dp[15001];
int main(){
	int m, n, e_max=0;
	int res = 0;
	cin >> m >> n;
	for(int i=1; i<=m; i++){
		scanf("%d", &t[i]);
	}	
	for(int i=1; i<=n; i++){
		int s, e, y; 
		scanf("%d %d %d", &s, &e, &y);
		a[e].push_back({s, (e-s)*t[y]});
		e_max = max(e_max, e);
	}
	for(int i=1; i<=e_max; i++){
		dp[i] = dp[i-1];
		for(int j=0; j<a[i].size(); j++){
			int start = a[i][j].first;
			dp[i] = max(dp[i], dp[start]+a[i][j].second);
		}
		res = max(dp[i], res);
	}
	cout << res;
}
