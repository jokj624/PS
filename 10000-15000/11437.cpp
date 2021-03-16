//AC 
//BOJ 11437 LCA
//https://www.acmicpc.net/problem/11437
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NODE 50002
vector<int> tree[NODE];
int depth[NODE]; 
int parent[NODE];
bool check[NODE];
int lca(int a, int b){
	if(depth[a]<depth[b]){
		swap(a,b);
	}
	while(depth[a]!=depth[b]){
		a= parent[a];
	}
	while(a!=b){
		a=parent[a];
		b=parent[b];
	}
	return a;
}
int main(){
	int n, m;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	queue<int> q;
	check[1] = true;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<tree[x].size(); i++){
			int y =tree[x][i];
			if(!check[y]){
				parent[y] = x;
				depth[y] = depth[x]+1;
				q.push(y);
				check[y] = true;
			}
		}
	}
	cin >> m;
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}
