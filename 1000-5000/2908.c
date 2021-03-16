//AC
//BOJ 2908 상수 
//https://www.acmicpc.net/problem/2908 
#include <stdio.h>
#include <stdlib.h>
int main(){
	int a, b, i, max;
	char num[4];
	char num2[4];
	for(i=0; i<3; i++){
		scanf("%c", &num[2-i]);
	}
	scanf("%c", &num[3]);
	for(i=0; i<3; i++){
		scanf("%c", &num2[2-i]);
	}
	a = atoi(num);
	b = atoi(num2);
	max = a > b? a : b;
	printf("%d", max);
	return 0;
}
