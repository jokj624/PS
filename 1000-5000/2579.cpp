//AC
//BOJ 2579 계단 오르기 
//https://www.acmicpc.net/problem/2579 
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int arr[301];
	int dp[301];
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}
	dp[2] = max(arr[1]+arr[2], arr[2]);
	dp[3] = max(arr[1]+arr[3], arr[2]+arr[3]);
	for(int i=4; i<=n; i++){
		dp[i] = max((dp[i-3]+arr[i]+arr[i-1]), (dp[i-2]+arr[i]));
	}
	cout << dp[n];
	return 0;
}
