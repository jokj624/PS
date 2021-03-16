//AC
//BOJ 6086 최대 유량
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, res = 0;
int c[150][150], f[150][150], d[150];
vector<int> v[150];
void netFlow(int start, int end){
	while(1){
		int flow = INF;
		fill(d, d+150, -1);
		queue<int> q;
		q.push(start);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int y : v[x]){
				if(c[x][y]-f[x][y] > 0 && d[y] == -1){
					q.push(y);
					d[y] = x;
					if(y==end)	break;
				}
			}
		}
		if(d[end] == -1)	break;
		for(int i=end; i!=start; i=d[i]){
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		for(int i=end; i!=start; i=d[i]){
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		res += flow;
	}
}
int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		char a, b;
		int t;
		cin >> a >> b >> t;
		v[a-'A'].push_back((b-'A'));
		v[b-'A'].push_back((a-'A'));
		c[a-'A'][b-'A'] += t;
		c[b-'A'][a-'A'] += t;
	}
	netFlow(0, 25);
	printf("%d", res);
	return 0;
}
