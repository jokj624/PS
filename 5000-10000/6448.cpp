//AC
//BOJ 6448 Stockbroker Grapevine
//https://www.acmicpc.net/problem/6448
#include <iostream>
#include <cstring>
#define MAX 987654321
using namespace std;
int d[101][101];
int main(){
	while(1){
		int n;
		scanf("%d", &n);
		if(n==0)	break;
		bool check = true;
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=n; j++){
					d[i][j] = MAX;
			}
		}
		int ans = MAX, res = MAX,t, a, b, min_stock = 0;
		for(int i=1; i<=n; i++){
			scanf("%d", &t);
			for(int j=0; j<t; j++){
				scanf("%d %d", &a, &b);
				d[i][a] = b;
				d[i][i] = 0;
			}
		}
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
		for(int i=1; i<=n; i++){
			res = 0;
			bool dis = true;
			for(int j=1; j<=n; j++){
				if(d[i][j] == MAX){
					dis = false;
					break;
				}
				else{
					if(res < d[i][j])	res = d[i][j];
				}
			}
			if(ans>res && dis==true){
				ans = res;
				min_stock = i;
				check = false;
			}
		}
		if(check)	printf("disjoint\n");
		else	printf("%d %d\n", min_stock, ans);
	}
	return 0;
}
