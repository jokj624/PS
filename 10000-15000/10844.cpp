//AC
//BOJ 10844 쉬운 계단 수 
//https://www.acmicpc.net/problem/10844
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long dp[101][10] = {0};
	for(int i=1; i<=9; i++){
		dp[1][i] = 1;
	}
	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			if(j-1 < 0)	dp[i][j] = dp[i-1][j+1] % 1000000000;
			else if(j == 9)	dp[i][j] = dp[i-1][j-1] % 1000000000;
			else	dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1])%1000000000;
		}
	}
	long long total = 0;
	for(int i=0; i<=9; i++){
		total =(total+dp[n][i])%1000000000;
	}
	cout << total % 1000000000<<endl;
}
