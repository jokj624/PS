//AC
//BOJ 11053 가장 긴 증가하는 부분 수열
//https://www.acmicpc.net/problem/11053 
#include <iostream>
using namespace std;
int main(){
	int arr[1001] = {0};
	int dp[1001] = {0};
	int cnt=1;
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}

	int ans=1;
	dp[1] = 1;
	for(int i=1; i<=n; i++){
		int max_num = 0;
		for(int j=1; j<i; j++){
			if(arr[i] > arr[j]){
				max_num = max(max_num, dp[j]);
			}
			dp[i] = max_num+1;
			ans = max(ans, dp[i]);
		}
	}
	cout << ans;
	return 0;
}
