//AC 
//BOJ 2003 수들의 합2 
//https://www.acmicpc.net/problem/2003
#include <iostream>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n+1];
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	int l=0, r=0, cnt=0;
	while(r<n){
		int sum = 0;
		for(int i=l; i<=r; i++){
			sum+=arr[i];
		}
		if(sum==m){
			cnt++;
			r++;
		}
		else if(sum < m){
			r++;
		}
		else{
			l++;
		}
	} 
	printf("%d", cnt);
	return 0; 
} 
