//AC
//BOJ 3986 좋은 단어 
//https://www.acmicpc.net/problem/3986 
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main(){
	int t, len, cnt=0;
	char str[100000];
	scanf("%d", &t);
	while(t--){
		stack<char> word;
		scanf("%s", str);
		len = strlen(str);
		for(int i=0; i<len; i++){
			if(word.empty()){
				word.push(str[i]);
				continue;
			}
			if(word.top() == str[i]){
				word.pop();
			}
			else{
				word.push(str[i]);
			}
		}
		if(word.empty())	cnt++;
		str[0] = '\0';
	}
	printf("%d", cnt);
	return 0;
}
