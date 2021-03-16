//AC
//BOJ 2606 바이러스_ DFS
// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visit[101]={false}; 
vector<int> met[101];
int dfs(int start);
int cnt=0;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		int u, ver;
		cin >> u >> ver;
		met[u].push_back(ver);
		met[ver].push_back(u);
	}
	for(int i=1; i<=n; i++){
		sort(met[i].begin(), met[i].end());
	} 
	dfs(1);
	cout << (cnt-1);
}
int dfs(int start){
	cnt++;
	visit[start] = true;
	for(int i=0; i < met[start].size(); i++ ){
		int next = met[start][i];
		if(visit[next]==false)	dfs(next);
	}
}
