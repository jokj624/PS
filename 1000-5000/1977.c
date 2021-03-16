//AC
//BOJ 1977 완전 제곱수
//https://www.acmicpc.net/problem/1977 
#include <stdio.h>
#include <math.h>
int n, m;
void square(int a, int b){
	int i, sum = 0, j=0;
	int arr[10001] = {0};
	for(i=a;i<=b; i++){
		if(i*i >= n && i*i <=m){
			arr[j] = i*i;
			sum += arr[j];
			j++;
		}
	}
	if(arr[0] == 0){
		printf("-1");
	}
	else 	printf("%d\n%d", sum,arr[0] );
}
int main(){
	int temp, temp2;
	scanf("%d %d", &n, &m);
	temp = sqrt(n);
	temp2 = sqrt(m);
	square(temp, temp2);
	return 0;
}
