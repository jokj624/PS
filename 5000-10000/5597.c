//AC
//BOJ 5597 과제 안 내신분..?
//https://www.acmicpc.net/problem/5597 
#include <stdio.h>
int main(){
	int arr[30] = {0};
	int num, i;
	for(i=0; i<28; i++){
		scanf("%d", &num);
		arr[num-1] = num;
	}
	for(i=0; i<30; i++){
		if(arr[i] == 0) 	printf("%d\n", i+1);
	}
	return 0;
}
