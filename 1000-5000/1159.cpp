//AC
//BOJ 1159 ?援?
//https://www.acmicpc.net/problem/1159 
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool comp(char a, char b){
	return a<b;
}
int main(){
	string s;
	int n;
	int arr[31]={0};
	char arr2[30];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		arr[s[0]-'a']++;
	}
	int idx= 0;
	for(int i=0; i<27;i++){
		if(arr[i] >= 5){
			arr2[idx++] = i+'a';
		}
	}
	sort(arr2, arr2+idx, comp);
	if(idx==0){
		cout << "PREDAJA";
	}
	else{
		for(int i=0; i<idx; i++){
			cout << arr2[i];
		}
	}
}
