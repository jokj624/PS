//AC 
//BOJ 11659 구간 합 구하기 4 
//https://www.acmicpc.net/problem/11659
#include <iostream>
using namespace std;
int arr[100001];
int s[100001];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	s[1] = arr[1];
	for(int i=2; i<=n;i++){
		s[i] = s[i-1]+arr[i];
		
	}
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a==b)	printf("%d\n",arr[a]);
		else	printf("%d\n", s[b]-s[a-1]);
	}
	return 0;
}
