//AC
//BOJ 14953 Game Map
//https://www.acmicpc.net/problem/14953 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t[100001];
int dp[100001];
vector<int> v[100001];
int dfs(int cur){
	if(dp[cur])	return dp[cur];
	int cnt = 1;
	for(int i = 0; i<v[cur].size(); i++){
		int next = v[cur][i];
		if(t[next] > t[cur]){
			cnt = max(1+dfs(next), cnt);
		}
	}
	return dp[cur] = cnt;
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		t[a]++;	t[b]++;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int res = 0;
	for(int i=0; i<n; i++){
		res = max(res, dfs(i));
	}
	cout << res;
}
