//AC
//BOJ 2562 최댓값 
//https://www.acmicpc.net/problem/2562
#include <stdio.h>
int main(){
	int arr[11], i, max, temp=0;
	for(i=0; i<9; i++){
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	for(i=1; i<9; i++){
		if(arr[i] > max){
			temp=i;
			max = arr[i];
		}
	}
	printf("%d\n%d", max, temp+1);
	return 0;
}
