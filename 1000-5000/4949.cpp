//AC
//BOJ 4949 균형잡힌 세상 
// https://www.acmicpc.net/problem/4949
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
stack<char> s;
char str[101];
string check(char str[]);
int main(){
	while(1){
		cin.getline(str,101,'\n');
		if(str[0] == '.')	break;
		else{
			cout << check(str) << endl;
		}
		while(!s.empty())	s.pop();
	}
	return 0;
}
string check(char str[]){
	char ch;
	for(int i=0; i<strlen(str); i++){
		ch = str[i];
		if(ch == '(' || ch =='[')	s.push(ch);
		else if(ch == ')'){
			if(s.empty())	return "no";
			if(s.top()=='(')	s.pop();
			else	return "no";
		}
		else if(ch == ']'){
			if(s.empty())	return "no";
			if(s.top()=='[')	s.pop();
			else	return "no";
		}
	}
	if(s.empty())	return "yes";
	else	return "no";
}
