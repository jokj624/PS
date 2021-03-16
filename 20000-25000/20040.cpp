//AC
//BOJ 20040 사이클 게임
//https://www.acmicpc.net/problem/20040 
//ACM-ICPC 예선 E번 
#include <iostream>
using namespace std;
int parent[500001];
int Find(int x){
	if(parent[x]==x)	return x;
	else 	return parent[x] = Find(parent[x]);
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	parent[y] = parent[x];
}
int main(){
	int n, t, ans=0;
	cin >> n >> t;
	for(int i=0; i<n; i++){
		parent[i] = i;
	}
	for(int i=0; i<t; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(Find(a)==Find(b) && ans == 0){
			ans=i+1;
		}
		else{
			Union(a, b);
		}
	}
	cout << ans;
	return 0;
} 
