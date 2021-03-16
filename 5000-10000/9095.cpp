//AC
//BOJ 9095 1,2,3 더하기 
// https://www.acmicpc.net/problem/9095
#include <iostream>
using namespace std;
int main(){
	int t , n;
	cin >> t;
	int dp[12] = {0};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while(t--){
		cin >> n;
		for(int i=4; i<=n; i++){
			dp[i] = dp[i-1]+ dp[i-2] + dp[i-3];
		}

		cout << dp[n] << endl;
	}
}
