//AC
//BOJ 1205 등수 구하기 
//https://www.acmicpc.net/problem/1205 
#include <iostream>
#include <algorithm>
using namespace std;
bool check(int a, int b){
	return a>b;
}
int main(){
	int n, score, p;
	int arr[52]={0};
	cin >> n >> score >> p;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	arr[n] = score;
	sort(arr, arr+(n+1), check);
	if(n >= p){
		if(arr[n-1] > score || arr[n] == score)	{
			cout << "-1";
			return 0;
		}
	}
	for(int i=0; i<p; i++){
		if(arr[i] == score){
			cout << i+1;
			break;
		}
	}
	return 0;
}
