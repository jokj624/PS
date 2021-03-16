//AC
//BOJ 11660 구간 합 구하기 5 
//https://www.acmicpc.net/problem/11660

#include <iostream>
using namespace std;
int arr[1026][1026];
int sum[1026][1026];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &arr[i][j]);
			sum[i][j] = sum[i][j-1]+sum[i-1][j] - sum[i-1][j-1]+arr[i][j];
		}
	}

	for(int i=0; i<m; i++){
		int x, x2, y, y2;
		scanf("%d %d %d %d",&x,&y,&x2,&y2);
		long long ans = sum[x2][y2]-sum[x2][y-1]-sum[x-1][y2]+sum[x-1][y-1];
		printf("%lld\n", ans);
	}
	return 0;
}
