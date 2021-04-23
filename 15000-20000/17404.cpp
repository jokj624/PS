//AC
//BOJ 17404 RGB 거리 2
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1001
#define INF 987654321
using namespace std;
int arr[SIZE][4];
int dp[SIZE][4];
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);
		fill(dp[i], dp[i]+4, INF);
	}
	int ans = INF;
	for(int j = 1; j<=3; j++){
		for(int k=1; k<=3; k++){
			if(j == k) {
				dp[1][k] = arr[1][k];
			} 
			else {
				dp[1][k] = INF;
			}
		}
		for(int i=2; i<=n; i++){
			dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + arr[i][1];
			dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + arr[i][2];
			dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + arr[i][3];	
		}
		for(int i=1; i<=3; i++){
			if(i == j)	continue;
			ans = min(ans, dp[n][i]);
		}
	}
	cout << ans;
	return 0;
}