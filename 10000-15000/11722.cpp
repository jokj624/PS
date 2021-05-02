//AC
//BOJ 11722 가장 긴 감소하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001];
int arr[1001];
int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	dp[0] = 1;
	int ans = dp[0];
	for(int i=1; i<N; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[j]>arr[i]){
				dp[i] = max(dp[j]+1,dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
