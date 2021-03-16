//AC
//BOJ 1463 1로 만들기 
// https://www.acmicpc.net/problem/1463 
#include <iostream>
#define MAX 987654321
using namespace std;
int dp[1000001]={0};
int main(){
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2; i<=n; i++){
		dp[i] = MAX;
		if(!(i%3)){
			dp[i] = min(dp[i/3], dp[i-1]);
		}
		if(!(i%2)){
			dp[i] = min(dp[i],min(dp[i/2], dp[i-1]));
		}
		dp[i] = min(dp[i],dp[i-1]);
		dp[i] += 1;
	}
	cout << dp[n];
}
