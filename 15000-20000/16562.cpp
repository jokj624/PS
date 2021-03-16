//AC
//BOJ 16562 친구비
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[10101];
int cost[10101];
int Find(int x){
	if(x == parent[x])	return x;
	parent[x] = Find(parent[x]);
	return parent[x];
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(cost[x] > cost[y])	parent[x] = y;
	else 	parent[y] = x;
}
int main(){
	int N, M, K, ans = 0;
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++){
		int c;
		scanf("%d", &cost[i]);
		parent[i] = i;
	}
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		if(Find(a)!=Find(b)){
			Union(Find(a), Find(b));
		}
	}
	for(int i=1; i<=N; i++){
		if(parent[i] == i)	ans+=cost[i];
	}
	if(ans <= K)	printf("%d\n", ans);
	else 	printf("Oh no");
	return 0;
}