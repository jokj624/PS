//AC
//BOJ 10871 X보다 작은 수
//https://www.acmicpc.net/problem/10871 
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
void check_min(int n, int x){
	for(int i=0; i<n;i++){
		if(a[i]<x)	printf("%d ", a[i]);
	}
}
int main(){
	int n, x;
	cin >> n >> x;
	for(int i=0; i<n; i++){
		int temp;
		scanf("%d" ,&temp);
		a.push_back(temp);
	}
	check_min(n,x);
	return 0;
}
