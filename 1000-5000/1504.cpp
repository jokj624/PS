//AC
//BOJ 1504 특정한 최단경로
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 987654321
using namespace std;
typedef pair<int, int> edge;
vector<edge> v[801];
int dijkstra(int start, int end, int n){
	int d[801]={0};
	priority_queue<edge, vector<edge>, greater<edge> > pq;
	pq.push({0, start});
	for(int i=1; i<=n; i++){
		d[i] = MAX;
	}
	d[start] = 0;
	while(!pq.empty()){
		int x = pq.top().second;
		pq.pop();
		for(int j=0; j<v[x].size(); j++){
			int y = v[x][j].first;
			int cost = v[x][j].second;
			if(d[y] > d[x]+cost){
				d[y] = d[x]+cost;
				pq.push({d[y], y});
			}
		}
	}
	return d[end];
}
int main(){
	int n, e;
	long long ans = 0;
	int v1, v2;
	cin >> n >> e;
	for(int i=0; i<e; i++){
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	cin >> v1 >> v2;
	int oneTov1 = dijkstra(1,v1,n);
	int oneTov2 = dijkstra(1,v2,n);
	int v1Tov2 = dijkstra(v1,v2,n);
	if(v1Tov2 == MAX){
		cout << "-1" << "\n";
		return 0;
	}
	ans = min((oneTov1+v1Tov2+dijkstra(v2,n,n)),
		(oneTov2+v1Tov2+dijkstra(v1,n,n)));
	
	if(ans >= MAX){
		cout << "-1" << "\n";
	}
	else	cout << ans <<"\n";
	return 0;
} 
