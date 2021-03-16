//AC
//BOJ 9461 파도반 수열 
//https://www.acmicpc.net/problem/9461 
#include <iostream>
using namespace std;
int main(){
	int t;
	long long dp[101];
	cin >> t;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	while(t--){
		int n;
		cin >> n;
		for(int i=4; i<=n; i++){
			dp[i] = dp[i-2] + dp[i-3];
		}
		cout << dp[n] << endl;
	}
	return 0;
}
