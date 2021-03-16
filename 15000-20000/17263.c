//AC
//BOJ 17263 Sort 마스터 배지훈 
//https://www.acmicpc.net/problem/17263 
#include <stdio.h>
#define MAX_SIZE 500000
int main(){
	int A[MAX_SIZE];
	int n, i, max;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	max = A[0];
	for(i=0; i<n; i++){
		if(max < A[i]) 	max = A[i];
	}
	printf("%d", max);
	return 0;
}
