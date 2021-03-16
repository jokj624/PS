//AC
//BOJ 2217 로프
//https://www.acmicpc.net/problem/2217
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a, int b){
	return a>b;
}
int main(){
	int n, max2=0, temp;
	int v[100000];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	sort(v, v+n, desc);
	for(int i=0; i<n; i++){
		temp = (i+1)*v[i];
		max2 = max(max2, temp);
	}
	cout << max2;
}
