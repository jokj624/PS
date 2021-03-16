//AC
//BOJ 10610 30 
//https://www.acmicpc.net/problem/10610 
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int arr[100001];
	cin >> n;
	if(n==30){
		cout << n;
		return 0;
	}
	int idx=0;
	while(n > 0){
		arr[idx] = n%10;
		n/=10;
		idx++;
	}
	cout << idx << " ";
	sort(arr, arr+idx);
	reverse(arr, arr+idx);
	for(int i=0; i<idx; i++){
		cout << arr[i];
	}
	if(arr[idx-1] != 0)	cout << "-1";
	else{
		int sum = 0;
		for(int i=0; i<idx; i++){
			sum += arr[i];
		}
		if(!(sum%3)){
			for(int i=0; i<idx; i++){
				printf("%d", arr[i]);
			}
		}
		else{
			cout << "-1";
		}
	}
	return 0;
}
