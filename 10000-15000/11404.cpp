//AC
//BOJ 11404 플로이드
//https://www.acmicpc.net/problem/11404 
#include <iostream>
#include <algorithm>
#define INF 99999999
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int d[n+1][n+1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			d[i][j] = INF;
		}
	}
	for(int i=0; i<m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j)	continue;
				if(d[i][k]!=INF && d[k][j]!=INF){
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(d[i][j]==INF)	cout << 0 << " ";
			else 	cout << d[i][j] << " ";
			if(j==n)	printf("\n");
		}
	}
	return 0;
}
