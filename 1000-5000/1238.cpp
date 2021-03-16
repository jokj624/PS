//AC
//BOJ 1238 파티
// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> edge;
vector<edge> v[1001]; 
vector<edge> r_v[1001];
int main(){
	int n, m, x, me=0;
	cin >> n >> m >> x;
	int d[n+1];
	int d2[n+1];
	fill(d,d+n+1, INF);
	fill(d2,d2+n+1, INF);
	for(int i=0; i<m; i++){
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		if(s==e && s==x){
			me = c;
			continue;
		}
		v[s].push_back(make_pair(e,c));
		r_v[e].push_back(make_pair(s,c));
	}
	priority_queue<edge, vector<edge> > pq;
	d[x] = 0;
	pq.push(make_pair(0, x));
	while(!pq.empty()){
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for(int i=0; i<v[cur].size(); i++){
			int next = v[cur][i].first;
			int nextcost = v[cur][i].second;
			if(d[next]>d[cur]+nextcost){
				d[next] = d[cur]+nextcost;
				pq.push(make_pair(d[next], next));
			}
		}
	}
	d2[x] = 0;
	pq.push(make_pair(0,x));
	while(!pq.empty()){
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for(int j=0; j<r_v[cur].size(); j++){
			int next = r_v[cur][j].first;
			int nextcost = r_v[cur][j].second;
			if(d2[next]>d2[cur]+nextcost){
				d2[next] = d2[cur]+nextcost;
				pq.push(make_pair(d2[next],next));
			}
		}
	}	
	for(int i=1; i<=n; i++){
		d[i] += d2[i];
	}
	int min_d = 0;
	for(int i=1; i<=n; i++){
		min_d = max(min_d, d[i]);
	}
	min_d = max(min_d, me);
	printf("%d\n", min_d);
	return 0;
}
