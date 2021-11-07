//AC
//BOJ 2266 금고테스트
#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int dp[600][600]; 

int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= k; i++) { 
		for (int j = 1; j <= n; j++) { 
			if (i == 1) {
				dp[i][j] = j;
				continue;
			}
			if (i > j) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			dp[i][j] = INF;
			for (int k = 1; k <= j; k++) {
				dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
			}
		}
	}
	cout << dp[k][n];

	return 0;
}
