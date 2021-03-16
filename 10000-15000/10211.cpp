//AC
//BOJ 10211 Maximum Subarray
//https://www.acmicpc.net/problem/10211
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int arr[1000];
		bool check = false;
		int dp[1000]={0};
		int n, max_num=-1000000000;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &arr[i]);
		}
		dp[1] = arr[1];
		for(int i=2; i<=n; i++){
			dp[i] = arr[i] + max(dp[i-1],0);
		}
		for(int i=1; i<=n; i++){
			max_num = max(max_num, dp[i]);
		}
		printf("%d\n", max_num);
	}
	return 0;
}
