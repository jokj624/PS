//AC
//BOJ 1890 점프
//https://www.acmicpc.net/problem/1890 
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long int jump[n+2][n+2];
	long long dp[n+2][n+2];
	dp[0][0] = 0; dp[0][1] = 0; dp[1][0]=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%lld", &jump[i][j]);
			dp[i][j]= 0;
		}
	}
	dp[1][1] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(jump[i][j]==0)	continue;
			int x = jump[i][j]+i;
			int y = jump[i][j]+j;
			if(x<=n)
				dp[x][j]+= dp[i][j];
			if(y<=n)
			 	dp[i][y] += dp[i][j];
		}
	}
	cout << dp[n][n];
	return 0;
}
