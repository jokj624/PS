//AC
//BOJ 12790 Mini Fantasy War
//https://www.acmicpc.net/problem/12790
#include <stdio.h>
int cal(int arr[]);
int main(){
	int n,i,j;
	int arr[8];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0; j<8; j++){
			scanf("%d", &arr[j]);
		}
		for(j=0; j<4; j++){
			arr[j] += arr[j+4];
		}
		cal(arr);
	}
	return 0;
}
int cal(int arr[]){
	int i, final;
	if(arr[0] < 1) 	arr[0] = 1;
	if(arr[1] < 1) 	arr[1] = 1;
	if(arr[2] < 0) 	arr[2] = 0;
	final = arr[0] + 5*arr[1] + 2*arr[2] + 2*arr[3];
	printf("%d\n", final);
}
