//AC
//BOJ 2294 동전 2
//https://www.acmicpc.net/problem/2294

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int value[101];
int dp[MAX];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &value[i]);
	}
	dp[0] = 0;
	for(int i=1; i<=k; i++){
		dp[i] = MAX;
	}
	for(int i=1; i<=n; i++){
		for(int j=value[i]; j<=k; j++){
			dp[j] = min(dp[j], dp[j-value[i]]+1);
		}
	}
	if(dp[k]!= MAX)	printf("%d\n", dp[k]);
	else	printf("-1\n");
	return 0;
} 
