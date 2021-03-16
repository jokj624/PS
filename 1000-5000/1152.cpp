//AC
//BOJ 1152 단어의 개수 
//https://www.acmicpc.net/problem/1152 
#include <stdio.h>
#include <string.h>
int main(){
	int cnt = 0,i,length;
	char arr[1000001];
	gets(arr);
	length = strlen(arr);
	if(arr[0] != ' '){
		for(i=0;i<length; i++){
			if(arr[i] == ' ')	cnt++;
		}
	}
	else if(arr[0] == ' '){
		for(i=1; i<length; i++){
			if(arr[i]==' ')	cnt++;
		}
	}
	if(arr[length-1] == ' ')	printf("%d", cnt);
	else	printf("%d", cnt+1);
	return 0;
}
