//AC
//BOJ 1761 정점들의 거리  
//https://www.acmicpc.net/problem/1761
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define MAX 40002
vector<pair<int, int> > tree[MAX];
int par[MAX]; int depth[MAX];	int d[MAX];
bool check[MAX];
int lca(int a, int b){
	int ans=0;
	if(depth[a]<depth[b]){
		swap(a,b);
	}
	while(depth[a]!=depth[b]){
		ans+=d[a];
		a= par[a];
	}
	while(a!=b){
		ans+=d[a];	
		ans+=d[b];
		a=par[a];
		b=par[b];
	}
	return ans;
}
int main(){
	int n, t;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		tree[u].push_back(make_pair(v,c));
		tree[v].push_back(make_pair(u,c));
	}
	queue<int> q;
	check[1] = true;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<tree[x].size(); i++){
			int y =tree[x][i].first;
			if(!check[y]){
				par[y] = x;
				depth[y] = depth[x]+1;
				d[y]=tree[x][i].second;
				q.push(y);
				check[y] = true;
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		int u,v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u,v));

	}
}
