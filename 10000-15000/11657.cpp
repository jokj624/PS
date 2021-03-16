//AC
//BOJ 11657 타임머신
//https://www.acmicpc.net/problem/11657 
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999999
using namespace std;
struct edge{
	int from, to, cost;
};
int main(){
	int n, m;
	long long d[501];
	bool negative_cycle = false;
	cin >> n >> m;
	vector<edge> graph(m);
	for(int i=0; i<m; i++){
		cin >> graph[i].from >> graph[i].to >> graph[i].cost;
	}
	d[1] = 0;
	for(int i=2; i<=n; i++){
		d[i] = INF;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			int x = graph[j].from;
			int y = graph[j].to;
			int z = graph[j].cost;
			if(d[x]!=INF && d[y] > d[x]+z){
				d[y] = d[x]+z;
				if(i==n)	negative_cycle = true;
			}
		}
	}
	if(negative_cycle)	printf("-1\n");
	else{
		for(int i=2; i<=n; i++){
			if(d[i]==INF)	{
				printf("-1\n");
			}
			else	cout << d[i] << endl;
		}
	}
	return 0;
}
