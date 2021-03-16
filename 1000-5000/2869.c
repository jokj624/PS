//AC
//BOJ 2869 달팽이는 올라가고 싶다 
//https://www.acmicpc.net/problem/2869
#include <stdio.h>
int main(){
	int a,b,v;
	scanf("%d %d %d", &a, &b, &v);
	printf("%d", (v-b-1)/(a-b)+1);
	return 0;
}
