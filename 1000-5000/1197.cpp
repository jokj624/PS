//AC
//BOJ 1197 최소 스패닝 트리
//https://www.acmicpc.net/problem/1197 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;
struct Edge{
	int start, end, cost;
	bool operator < (const Edge& other) const{
		return cost < other.cost;
	}
};
int parent[MAX];
int Find(int x){
	if(parent[x]==x)	return x;
	else	return parent[x]=Find(parent[x]);
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	parent[y] = parent[x];
}
int main(){
	int v, e, ans=0;
	cin >> v >> e;
	for(int i=1; i<=v; i++){
		parent[i] = i;
	}
	vector<Edge> graph(e);
	for(int i=0; i<e; i++){
		cin >> graph[i].start >> graph[i].end >> graph[i].cost;
	}
	sort(graph.begin(), graph.end());
	for(int i=0; i<e; i++){
		if(Find(graph[i].start)!=Find(graph[i].end)){
			ans += graph[i].cost;
			Union(Find(graph[i].start), Find(graph[i].end));
		}
	}
	printf("%d", ans);
	return 0;
}
