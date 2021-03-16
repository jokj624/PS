//AC
//BOJ 1918 후위표기식
//https://www.acmicpc.net/problem/1918
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101
int push(char data);
int pop();
int pre(char data);
char arr[MAX_SIZE];
char stack[MAX_SIZE];
int top = -1;
int main(){
	int pos=0;
	char data, ch;
	scanf("%s", arr);
	while((data = arr[pos++] )!= '\0'){
		if(data >= 'A' && data <='Z')	printf("%c", data);
		else if(data == '(')	push(data);
		else if(data == ')'){
			while((ch = pop()) != '(')	printf("%c", ch);	
		}
		else{
			while((pre(data) <= pre(stack[top])) && top != -1){
				printf("%c", pop());
			}
			push(data);
		}	
	}
	while(top != -1){
		printf("%c", pop());
	}
	return 0;
}
int push(char data){
	stack[++top] = data;
}
int pop(){
	return stack[top--];
}
int pre(char data){
	if(data == '(')	return 0;
	else if(data == '+' || data=='-')	return 1;
	else if(data =='*'|| data=='/')	return 2;
}

