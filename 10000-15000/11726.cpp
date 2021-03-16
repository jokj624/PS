//AC
//BOJ 11726 2xn 타일링
//https://www.acmicpc.net/problem/11726
#include <iostream>
using namespace std;
int main(){
	long dp[1001];
	long n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-1]+dp[i-2])% 10007;
	}
	cout << dp[n]%10007;
}
