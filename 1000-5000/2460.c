//AC
//BOJ 2460 지능형 기차
//https://www.acmicpc.net/problem/2460
#include <stdio.h>
int main(){
	int arr[10]={0};
	int i, in, out, max = 0;
	for(i=0; i<10; i++){
		scanf("%d %d", &out, &in);
		if(i==0) 	arr[i] = in;
		else 	arr[i] = arr[i-1] - out + in;
	}
	for(i=0; i<10; i++){
		if(arr[i]>max) 	max=arr[i];
	}
	printf("%d", max);
	return 0;
}
