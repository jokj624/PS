//AC
//BOJ 2851 슈퍼 마리오 
//https://www.acmicpc.net/problem/2851 
#include <iostream>
using namespace std;
int main(){
	int arr[10];
	for(int i=0; i<10; i++){
		cin >> arr[i];
	}
	int score = 0, gap=0, temp;
	for(int i=0; i<10; i++){
		score+=arr[i];
		gap = 100 - score;
		if(gap == 0)	{
			cout << 100;
			return 0;
		}
		else if(gap < 0){
			temp = i;
			break;
		}
	}
	if(gap<0){
		score -= arr[temp];
		if(-gap > (100 - score)){
			cout << score;
		}
		else{
			cout << (100-gap);
		}
	}
	else if(gap>0){
		cout << score;
	}
	return 0;
}
