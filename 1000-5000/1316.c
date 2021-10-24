//AC
//BOJ 1316 그룹 단어 체커
#include <stdio.h>
#include <string.h>
int group_check(char arr[]);
int main(){
	int n, count = 0 , a;
	char arr[100];
	scanf("%d", &n);
	while(n--){
		scanf("%s", arr);
		a = group_check(arr);
		if(a == 1) 	count++;
	}
	printf("%d", count);
	return 0;
}
int group_check(char arr[]){
	int i, j, k=0;
	char arr2[100];
	for(i=0;i<strlen(arr);i++){
		if(arr[i]!= arr[i+1]){
			for(j=i+2; j<strlen(arr);j++){
				if(arr[i] == arr[j]) 	return -1;
			}
		}
	}
	return 1;
}
