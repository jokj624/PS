//AC
//BOJ 15650 n과 m (2)
//https://www.acmicpc.net/problem/15650 
#include <iostream>
using namespace std;
int choice[10];
int arr[10];
int n, m;
void combination(int num, int idx){
	if(idx > m)	{
		for(int i=1; i<=m; i++){
			printf("%d ", choice[i]);
		}
		printf("\n");
		return;
	}
	if(num > n){
		return;
	}
	choice[idx] = arr[num];
	
	combination(num+1, idx+1);
	combination(num+1, idx);
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		arr[i] = i;
	}
	combination(1,1);
	return 0;
}
