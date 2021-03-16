//AC
//BOJ 12865 평범한 배낭 
#include <iostream>
using namespace std;
int dp[103][100010];
int w[103];
int v[103];
int main(){
	int n, k, ans=0;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		scanf("%d %d", &w[i], &v[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=1; j<=k; j++){
			if(i==0){
				if(j-w[0] >= 0)	dp[0][j] = v[0];
				continue;
			} 
			if(j-w[i] >= 0){
				dp[i][j] = max(dp[i-1][j-w[i]]+v[i],
						 dp[i-1][j]);
			}
			else	dp[i][j] = dp[i-1][j];
		}
		ans = max(ans, dp[i][k]);
	}
	cout << ans << "\n";
	return 0;
}
