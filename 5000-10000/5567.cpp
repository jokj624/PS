//AC
//BOJ 5567 결혼식
//https://www.acmicpc.net/problem/5567 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visit[502]={false}; 
vector<int> met[502];
void bfs(int start);
int cnt = 0;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		int u, v;
		cin >> u >> v;
		met[u].push_back(v);
		met[v]. push_back(u);
	}
	bfs(1);
	cout << cnt;
}
void bfs(int start){
	queue<int> q;
	visit[start] = true;
	q.push(start);
	for(int i=0; i<= met[start].size(); i++){	// 내 친구+나까지  
		int now = q.front();
		q.pop();
		for(int j=0; j<met[now].size(); j++){
			int next = met[now][j];
			if(visit[next]==false){
				visit[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}
}
