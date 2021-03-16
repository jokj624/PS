//AC
//BOJ 11438 LCA2
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 101010
using namespace std;
vector<int> v[SIZE];
int pa[SIZE][20], D[SIZE], N,M;
void dfs(int parent, int child, int d){
	pa[child][0] = parent;
	D[child] = d;
	for(int tmp : v[child]){
		if(tmp != parent){
			dfs(child, tmp, d+1);
		}
	}
}
int lca(int s, int e){
	if(D[s] < D[e])	swap(s, e);
	for(int i=19; i>=0; i--){
		if(1<<i <= D[s]-D[e])	s = pa[s][i];
	}
	if(s==e)	return s;
	
	for(int i=19; i>=0; i--){
		if(pa[s][i] != pa[e][i]){
			s = pa[s][i];
			e = pa[e][i];
		}
	}
	return pa[s][0];
}
int main(){
	cin >> N;
	for(int i=0; i<N-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0, 1, 0);
	for(int i=1; i<20; i++){
		for(int j=1; j<=N; j++){
			pa[j][i] = pa[pa[j][i-1]][i-1];
		}
	}
	cin >> M;
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a,b));
	}
	return 0;
}