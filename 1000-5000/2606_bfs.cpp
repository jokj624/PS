//AC
//BOJ 2606 바이러스_ BFS
// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visit[101]={false}; 
vector<int> met[101];
int bfs(int start);
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
	bfs(1);
	cout << (cnt-1);
}
int bfs(int start){
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		cnt++;
		for(int i=0; i<met[now].size(); i++){
			int next = met[now][i];
			if(visit[next]==false) {
				visit[next] = true;
				q.push(next);
			}
		} 
	}
}
