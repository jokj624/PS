//AC
//BOJ 2225 합 분해 
//www.acmicpc.net/problem/2225 
#include <iostream>
using namespace std;
long long dp[201][201];
long long MOD = 1000000000;
int main(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=k; i++){
		dp[0][i] = 1;
		dp[1][i] = i;
	}
	for(int j=0; j<=n; j++){
		dp[j][1] = 1;
		dp[j][0] = 0;
	}
	if(n==1){
		cout << dp[n][k];
		return 0;
	}
	for(int i=2; i<=k; i++){
		for(int j=2; j<=n; j++){
			for(int p=0; p<=j; p++){
				dp[j][i] += dp[j-p][i-1];
				dp[j][i] %= MOD;
			}
		}
	}
	cout << dp[n][k] % MOD;
	return 0;
}
