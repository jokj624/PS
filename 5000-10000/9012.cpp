//AC
//BOJ 9012 괄호 
//https://www.acmicpc.net/problem/9012 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string VPS(string str);
int main(){
	int T;
	cin >> T;
	while (T--){
		string str;
		cin >> str;
		cout << VPS(str) << endl; 
	}
}
string VPS(string str){
	stack<char> s;
	for(int i = 0; i<str.length(); i++){
		if(str[i]=='('){
			s.push(str[i]);
		}
		else if(str[i]==')'){
			if(s.empty())	return "NO";
			else{
				s.pop();
			}
		}	
	}
	if(s.empty())	return "YES";
	else 	return "NO";
}
