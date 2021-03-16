//AC
//BOJ 2748 피보나치 수 2 
// https://www.acmicpc.net/problem/2748
#include <iostream>
using namespace std;
int main(){
	long long dp[92];
	int n;
	dp[0] = 0;
	dp[1] = 1;
	cin >> n;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n];
}
