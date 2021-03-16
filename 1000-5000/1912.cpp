//AC
//BOJ 1912 연속합
//https://www.acmicpc.net/problem/1912 
#include <iostream>
using namespace std;
int main(){
	int n, arr[100001];
	int dp[100001];
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	if(n==0){
		dp[0] = max(0, arr[0]);
		cout <<dp[0];
		return 0;
	}
	dp[0] = arr[0];
	int max_num = dp[0];
	for(int i=1; i<n; i++){
		if(arr[i] > dp[i-1] + arr[i]){
			dp[i] = arr[i];
		}
		else{
			dp[i] = dp[i-1] + arr[i];
		}
		max_num = max(dp[i], max_num);
	}
	cout << max(max_num, dp[n-1]);
}
