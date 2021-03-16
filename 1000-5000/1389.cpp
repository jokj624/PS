//AC
//BOJ 1389 케빈 베이컨의 6단계 법칙
//https://www.acmicpc.net/problem/1389 
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int d[101][101];
int main(){
	int n, m, ans, res=INF;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			d[i][j] = INF; 
		}
	}
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		d[a][b] = 1;
		d[b][a] = 1;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j)	continue;
				if(d[i][k]!=INF && d[k][j]!=INF){
					d[i][j] = min(d[i][k]+d[k][j],d[i][j]);
				}	
			}
		}
	}
	int kevin;
	for(int i=1; i<=n; i++){
		ans=0;
		for(int j=1; j<=n; j++){
			if(i==j)	continue;
			ans += d[i][j];
		}
		if(res > ans){
			res = ans;
			kevin = i;
		}
	}
	cout << kevin;
}
