//AC
//BOJ 2012 등수 매기기 
//https://www.acmicpc.net/problem/2012 
#include <iostream>
#include <algorithm>
using namespace std; 
int main(){
	int n;
	long long ans = 0;
	int a[500000];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+n);
	for(int i=0; i<n; i++){
		ans = ans + abs((a[i] - (i+1)));
	}
	cout << ans;
	return 0;
}
