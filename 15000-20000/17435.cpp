//AC
//BOJ 17435 합성함수와 쿼리
#include <iostream>
#define SIZE 200005
using namespace std;
int ST[SIZE][20];
int main(){
	int n, m, x, Q;
	cin >> m;
	for(int i=1; i<=m; i++){
		scanf("%d",&ST[i][0]);
	}
	for(int i=1; i<20; i++){
		for(int j=1; j<=m; j++){
			ST[j][i] = ST[ST[j][i-1]][i-1];
		}
	}
	cin >> Q;
	for(int i=0; i<Q; i++){
		scanf("%d %d", &n, &x);
		for(int i=19; i>=0; i--){
			if(1<<i <= n){
				n -= (1<<i);
				x = ST[x][i];
			}
		}
		printf("%d\n", x);
	}
	return 0;
}