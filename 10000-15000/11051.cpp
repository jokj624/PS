//AC
// BOJ 11051 이항계수 2 
//https://www.acmicpc.net/problem/11051
#include <iostream>
using namespace std;
int arr[1002][1002];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(j==0){
				arr[i][j] = 1;
				continue;
			}	
			if(i==j){
				arr[i][j] = 1;
				continue;
			}	
			arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
			arr[i][j] %= 10007;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("%d", arr[n][k]);
}
