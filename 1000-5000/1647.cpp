//AC
//BOJ 1647 도시 분할 계획

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101010
using namespace std;
int parent[MAX];
struct Edge{
	int st, en, cost;
};
bool cmp(const Edge &a, const Edge &b){
	return a.cost < b.cost;
}
vector<Edge> v;
int Find(int x){
	if(x == parent[x])	return x;
	parent[x] = Find(parent[x]);
	return parent[x];
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	parent[y] = parent[x];
}
int main(){
	int N, M; 
	vector<int> max_e;
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		parent[i] = i;
	}
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({a, b, c});
	}
	long long ans = 0;
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<M; i++){
		if(Find(v[i].st) != Find(v[i].en)){
			ans += v[i].cost;
			Union(v[i].st, v[i].en);
			max_e.push_back(v[i].cost);
		}
	}
	printf("%lld", ans-max_e[max_e.size()-1]);
	return 0;
}