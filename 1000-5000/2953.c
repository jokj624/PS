//AC
//BOJ 2953 나는 요리사다
//https://www.acmicpc.net/problem/2953 
#include <stdio.h>
int main(){
	int arr[5]={0};
	int a, b, c, d, i, max;
	for(i=0; i<5; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		arr[i]=a+b+c+d;	
	}
	max=arr[0];
	for(i=1; i<5; i++){
		if(max < arr[i]){
			max = arr[i];
			a = i+1;
		}
	}
	if(max==arr[0]){
		printf("1 %d",arr[0]);
	}
	else{
		printf("%d %d", a, max);	
	}
}

