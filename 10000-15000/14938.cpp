//AC
//BOJ 14938 서강그라운드
#include <iostream>
#define INF 987654321
using namespace std;
int item[101];
int road[101][101];
int main(){
	int n, m, r, tmp, sum = 0, ans = 0;
	cin >> n >> m >> r;
	for(int i=1; i<=n; i++){
		scanf("%d", &item[i]);
	}
	for(int i=0; i<r; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		road[a][b] = c;
		road[b][a] = c;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(road[i][j] == 0){
				road[i][j] = INF;
			}
			if(i==j)	road[i][j] = 0;
		}
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(road[i][k] + road[k][j] < road[i][j]){
					road[i][j] = road[i][k] + road[k][j];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		sum = 0;
		for(int j=1; j<=n; j++){
			if(road[i][j] <= m){
				sum += item[j];
			}
		}
		ans = max(sum, ans);
	}
	cout << ans;
	return 0;
}