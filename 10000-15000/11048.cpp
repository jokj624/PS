//AC
//BOJ 11048 이동하기 
//https://www.acmicpc.net/problem/11048 
#include <iostream>
using namespace std;
int miro[1001][1001];
int dp[1001][1001];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &miro[i][j]);
			dp[i][j] = 0;
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
			dp[i][j] += miro[i][j];
		}
	}
	cout << dp[n][m];
}
