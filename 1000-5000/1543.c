//AC
//BOJ 1543 문서 검색
//https://www.acmicpc.net/problem/1543
#include <stdio.h>
#include <string.h>
#define MAX 2501
int main(){
	char arr[MAX];
	char str[51];
	int cnt=0, i=0, pos=0, temp=0;
	gets(arr);
	gets(str);
	while(i < strlen(arr)){
		if(arr[i++] != str[pos++])	{
			pos=0;
			temp++;
			i = temp;
		}
		else if(pos == strlen(str)){
			cnt++;
			pos = 0;
			temp = i;
		}
	}
	printf("%d", cnt);
	return 0;
}
