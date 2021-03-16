//AC
//BOJ 1916 최소비용 구하기 
//https://www.acmicpc.net/problem/1916 
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 99999999
using namespace std;
typedef pair<int, int> edge;
int main(){
	int n, m, start, end;
	cin >> n >> m;
	int d[n+1];
	bool c[n+1];
	vector<edge> graph[n+1];
	for(int i=0; i<m; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
	}
	for(int i=1; i<=n; i++){
		d[i] = INF;
		c[i] = false;
	}
	cin >> start >> end;
	d[start] = 0;
	priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, start));
	while(!pq.empty()){
		int x = pq.top().second;
		pq.pop();
		if(!c[x]){
			c[x] = true;
			for(int j=0; j<graph[x].size(); j++){
				int y = graph[x][j].first;
				if(d[y]>d[x]+graph[x][j].second){
					d[y] = d[x]+graph[x][j].second;
					pq.push(make_pair(d[y], y));
				}
			}
		}
	}
	cout << d[end] << endl;
}
