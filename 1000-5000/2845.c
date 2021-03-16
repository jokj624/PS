//AC
//BOJ 2845 파티가 끝나고 난 뒤
//https://www.acmicpc.net/problem/2845 
#include <stdio.h>
int main(){
	int num, m, arr[5], i;
	scanf("%d %d\n", &num, &m);
	for(i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	for(i=0; i<5; i++){
		printf("%d ", arr[i] - (num*m));
	}
	return 0;
}
