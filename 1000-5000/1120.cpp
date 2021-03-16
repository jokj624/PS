//AC
//BOJ 1120 문자열  
// https://www.acmicpc.net/problem/1120 
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	char a[51];
	char b[51];
	int cnt=0, result = 100000000;
	scanf("%s %s", a, b);
	int len = strlen(b) - strlen(a);
	int k=0;
	for(int i=0; i<=len; i++){
		for(int j=i; j<strlen(a)+i; j++){
			if(a[k]!=b[j])	cnt++;
			k++;
		}
		result = min(result, cnt);
		cnt=0; k=0;
	}
	printf("%d", result);
	return 0;
}
