//AC
//BOJ 6321 IBM 빼기 1
// https://www.acmicpc.net/problem/6321
#include <stdio.h>
#include <string.h>
int main(){
	int n, i, j;
	char str[50];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", str);
		for(j=0; j<strlen(str); j++){
			if(str[j] == 'Z') 	str[j] = 'A';
			else 	str[j] += 1;
		}
		printf("String #%d\n", i+1);
		printf("%s\n", str);
		printf("\n");
	}
}
