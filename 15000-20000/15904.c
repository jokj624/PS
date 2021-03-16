//AC
//BOJ 15904 UCPC는 무엇의 약자일까?
//https://www.acmicpc.net/problem/15904 
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1001
int main(){
	int i, cnt=0;
	char arr[MAX_SIZE];
	char test[MAX_SIZE] = "UCPC";
	scanf("%[^\n]s", arr);
	for(i=0; i<strlen(arr); i++){
		if(cnt==4) break;
		else if(arr[i] == test[cnt]) 	cnt++;
	}
	if(cnt == 4)	printf("I love UCPC");
	else	printf("I hate UCPC");
}
