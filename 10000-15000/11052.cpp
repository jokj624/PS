//AC
//BOJ 11052 카드 구매하기 
//https://www.acmicpc.net/problem/11052 
#include <iostream>
using namespace std;
int MAX(int a, int b){
	return a>b ? a : b;
}
int main(){
	int n;
	int arr[1001];
	int dp[1001];
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		dp[i] = 0;
	}
	dp[0] = 0;
	arr[0] = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i] = MAX(dp[i],(dp[i-j] + arr[j]));
		}
	}
	cout << dp[n];
}
