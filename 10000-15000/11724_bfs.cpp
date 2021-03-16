//AC
//BOJ 11724 연결 요소의 개수_BFS 
//https://www.acmicpc.net/problem/11724 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visit[1002]={false}; 
vector<int> met[1002];
int bfs(int start);
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		int u, v;
		cin >> u >> v;
		met[u].push_back(v);
		met[v]. push_back(u);
	}
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(visit[i] == false){
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
}
int bfs(int start){
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0; i<met[now].size(); i++){
			int next = met[now][i];
			if(visit[next]==false) {
				visit[next] = true;
				q.push(next);
			}
		} 
	}
}
