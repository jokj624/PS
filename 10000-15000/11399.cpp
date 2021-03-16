//AC
//BOJ 11399 ATM
//https://www.acmicpc.net/problem/11399
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int arr[1001];
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr,arr+n);
	int sum=0;
	int temp=0;
	for(int i=0; i<n; i++){
		arr[i] += temp;
		temp = arr[i];
		sum += arr[i];
	}
	cout << sum;
}
