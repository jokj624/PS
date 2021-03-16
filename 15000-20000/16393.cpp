//BOJ 16393  Lost Map
//AC
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 2501
using namespace std;
struct edge{
	int start, end, cost;	
};
bool cmp(const edge &e1, const edge &e2){
	return e1.cost < e2.cost;
}
int n;
int parent[MAX];
vector<edge> v;
int Find(int x){
	if(x==parent[x])	return x;
	parent[x] = Find(parent[x]);
	return parent[x];
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x < y)	parent[y] = x;
	else	parent[x] = y;
}
void mst(){
	for(edge e : v){
		int st = e.start;
		int ed = e.end;
		if(Find(st) != Find(ed)){
			if(st < ed) 	printf("%d %d\n", st, ed);
			else 	printf("%d %d\n", ed, st);
			Union(Find(st), Find(ed));
		}
	}
}
int main(){
	int tmp;
	cin >> n;
	for(int i=1; i<=n; i++){
		parent[i] = i;
		for(int j=1; j<=n; j++){
			scanf("%d", &tmp);
			if(i!=j){
				v.push_back({i, j, tmp});
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	mst();
	return 0;
}