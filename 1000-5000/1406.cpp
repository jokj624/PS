//AC
//BOJ 1406 에디터 
//https://www.acmicpc.net/problem/1406 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<char> left, right;
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)	left.push(s[i]);
	int N;
	cin >> N;
	char a;
	for(int i=0; i<N; i++){
		cin >> a;
		if(a == 'L'){
			if(!left.empty()){
				right.push(left.top());
				left.pop();
			}
		}
		else if(a == 'D')	{
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}
		else if(a=='B'){
			if(!left.empty())	left.pop();
		}	
		else if(a=='P'){
			char b;
			cin >> b;
			left.push(b);
		}
	}
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while(!right.empty()){
		cout<<right.top();
		right.pop();
	}
	
}
