//AC
//BOJ 17285 XORChic
//https://www.acmicpc.net/problem/17285
#include <stdio.h>
#include <string.h>
void change(char arr[], int key){
	int i=0;
	printf("CHICKENS");
	for(i=8; i<strlen(arr);i++){
		arr[i] = arr[i]^key;
		printf("%c",arr[i]);
	}
	
}
int main(){
	int key;
	char arr[100];
	scanf("%s", arr);
	key = arr[0]^'C';
	change(arr,key);	
}
