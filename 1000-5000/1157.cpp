//AC
//BOJ 1157 단어공부 
// https://www.acmicpc.net/problem/1157 

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin >> s;
	int a[26]={0};
	for(int i=0; i<s.size(); i++){
		if(s[i] >='A' && s[i]<='Z'){
			a[s[i]-'A']++;
		}
		else if(s[i]>='a' && s[i]<='z'){
			a[s[i]-'a']++;
		}
	}
	int max, temp, check=1;
	max = a[0];
	temp = 0;
	for(int i=1; i<26; i++){
		if(max < a[i])	{
			max = a[i];
			temp = i;
			check = 1;
		}	
		else if(max == a[i])	check = 0;
	}
	if(!check)	cout << "?";
	else{
		char ch;
		ch = temp + 65;
		cout << ch;
	}
	return 0;
}
