//AC
//BOJ 11057 오르막 수
//https://www.acmicpc.net/problem/11057 
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int dp[1001][10];
	dp[1][0] = 0;
	for(int i = 0; i <= 9; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i<=n; i++){
		for(int j=0; j<=9; j++){
			dp[i][j] = 0;
			for(int k=0; k<=j; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	int total = 0;
	for(int i=0; i<=9; i++){
		total += dp[n][i];
	}
	total %= 10007;
	cout << total << endl;
}
