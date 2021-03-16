//AC
//BOJ 1920 수 찾기 
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int arr[100001]={0};
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int num;
		scanf("%d", &num);
		printf("%d\n", binary_search(arr,arr+n,num) );
	}
	return 0;
}
