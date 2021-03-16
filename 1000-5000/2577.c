//AC
//BOJ 2577 숫자의 개수 
//https://www.acmicpc.net/problem/2577
#include <stdio.h>
void check(int mul){
	int arr[11]={0};
	int i;
	while(mul > 0){
		arr[mul%10]++;
		mul /= 10;
	}
	for(i=0; i<10; i++){
		printf("%d\n", arr[i]);
	}
}
int main(){
	int a,b,c, mul;
	scanf("%d %d %d", &a, &b, &c);
	mul = a*b*c;
	check(mul);
}
