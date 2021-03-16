//AC
//BOJ 9933 민균이의 비밀번호 
//https://www.acmicpc.net/problem/9933 
#include <stdio.h>
#include <string.h>
#define MAX 100
struct string{
	char arr[14];
};
struct string str[MAX];
int reverse(char *arr);
int main(){
	int n, i, j, temp;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", str[i].arr);
	}
	for(i=0; i<n; i++){
		reverse(str[i].arr);
		for(j=i+1; j<n; j++){
			if(!strcmp(str[i].arr, str[j].arr))	{
				temp = i;
				break;
			}
		}
	}
	j = strlen(str[temp].arr) / 2;
	printf("%d %c", strlen(str[temp].arr), str[temp].arr[j] );
	return 0;
}
int reverse(char *arr){
	int size = strlen(arr);
	char temp;
	int i;
	for(i=0; i<size/2; i++){
		temp = arr[i];
		arr[i] = arr[(size-1)-i];
		arr[(size-1)-i] = temp;
	}
}
