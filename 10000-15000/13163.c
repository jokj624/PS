//AC
//BOJ 13163 닉네임에 갓 붙이기 
// https://www.acmicpc.net/problem/13163
#include <stdio.h>
#include <string.h>
int change(int cnt, char str[]);
int main(){
	char str[102];
	int n, i, cnt;
	scanf("%d\n", &n);
	for(i=0; i<n; i++){
		cnt=0;
		gets(str);
		change(cnt, str);
	}
}
int change(int cnt, char str[]){
	char arr[102] = {0};
	int i, j=0;
	for(i=0; i<strlen(str); i++){
		if(cnt == 0){
			if(str[i] == ' ')	cnt++;
		}
		else{
			if(str[i] != ' ')	arr[j++] = str[i];
		}
	}
	printf("god%s\n",arr);
	return;
}
