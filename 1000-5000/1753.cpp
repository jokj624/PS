//AC
//BOJ 1753 최단경로
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAXN 20001
#define INF 987654321
using namespace std;
typedef pair<int, int> edge;
vector<edge> v[MAXN];
int n, e;
int d[MAXN];
void dijkstra(int start){
	priority_queue<edge, vector<edge>, greater<edge> > pq;
	for(int i=1; i<=n; i++){
		d[i] = INF;
	}
	d[start] = 0;
	pq.push({0, start});
	while(!pq.empty()){
		int x = pq.top().second;
		int curDis = pq.top().first;
		pq.pop();
		if(d[x] < curDis)	continue;

		for(int j=0; j<v[x].size(); j++){
			int y = v[x][j].first;
			int cost = v[x][j].second;
			int nextCost = d[x]+cost;
			if(d[y] > nextCost){
				d[y] = nextCost;
				pq.push({d[y], y});
			}
		}
	}
	return;
}
int main(){
	int start;
	cin >> n >> e >> start;
	for(int i=0; i<e; i++){
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({b,c});
	}
	dijkstra(start);
	for(int i=1; i<=n; i++){
		if(i!=start){
			if(d[i] == INF)	printf("INF\n");
			else 	printf("%d\n", d[i]);
		}
		else	printf("0\n");
	}
	return 0;
} 
