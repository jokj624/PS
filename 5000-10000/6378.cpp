//AC
//BOJ 6378 디지털 루트 
//https://www.acmicpc.net/problem/6378 
#include <stdio.h>
#include <string.h>
void check(char arr[]) {
	int sum = 0, i;
	char s[1000];
	while (strlen(arr)!=1) {
		for (i = 0; i < strlen(arr); i++) {
			sum += (arr[i] - '0');
		}
		sprintf(s, "%d", sum);
		arr[0] = '\0';
		strcpy(arr,s);
		s[0] = '\0';
		sum = 0;
	}
	printf("%s", arr);
}
int main() {
	char arr[1000];
	while (1) {
		scanf("%s", arr);
		if (arr[0] = '0')	break;
		else {
			if (strlen(arr) == 1) {
				printf("%s", arr);
			}
			else	check(arr);
		}
		arr[0] = '\0';
	}
}
