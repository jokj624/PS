//AC
//BOJ 10809 알파벳 찾기 
//https://www.acmicpc.net/problem/10809 
#include <stdio.h>
#include <string.h>
int main(){
	char arr[101];
	int alpha[27];
	int i, temp;
	scanf("%s", arr);
	int len = strlen(arr);
	for(i=0; i<26; i++){
		alpha[i] = -1;
	}
	for(i=0; i<len; i++){
		temp = arr[i] - 97;
		if(alpha[temp] == -1)	alpha[temp] = i; 
	}
	for(i=0; i<26; i++){
		printf("%d ", alpha[i]);
	}
	return 0;
} 
