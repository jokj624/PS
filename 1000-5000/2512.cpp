//AC
//BOJ 2512 예산
// https://www.acmicpc.net/problem/2512
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000];
int n, m;
bool check(int x){
	int cnt=0;
	for(int i=0; i<n; i++){
		if(arr[i] > x){
			cnt+=x;
		}
		else{
			cnt+=arr[i];
		}
	}
	if(cnt <= m)	return true;
	else	return false;
}
int main(){
	int l,r,ans=0, x;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	sort(arr,arr+n);
	l = 1;
	r = arr[n-1];
	while(l <= r){
		x = (l+r)/2;
		if(check(x)){
			l = x+1;
			ans = max(ans, x);
		}
		else{
			r = x-1;
		}
	}
	printf("%d", ans);
	return 0;
}
