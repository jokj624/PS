//AC
//BOJ 6118 숨바꼭질 
//https://www.acmicpc.net/problem/6118 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define INF 9999999
using namespace std;
int main(){
	int n, m;
	int max_d = 0;
	scanf("%d %d", &n, &m);
	int d[n+1];
	bool c[n+1];
	for(int i=1; i<=n; i++){
		d[i] = INF; 
		c[i] = false;
	}
	vector<int> v[n+1];
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	d[1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		int x = pq.top().second;
		pq.pop();
		if(!c[x]){
			c[x] = true;
			for(int j=0; j<v[x].size(); j++){
				int y = v[x][j];
				if(d[y]>d[x]+1){
					d[y] = d[x]+1;
					pq.push(make_pair(d[y], y));
				}
			}
		}
	}
	int node, cnt=0;
	for(int i=2; i<=n; i++){
		if(max_d < d[i]){
			max_d = d[i];
			node = i;
			cnt=0;
		}
		if(max_d==d[i]){
			cnt++;
		}
	}
	printf("%d %d %d\n", node, d[node], cnt);
	return 0;
}
