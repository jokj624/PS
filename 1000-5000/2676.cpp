//AC
//BOJ 2676 라스칼 삼각형
// https://www.acmicpc.net/problem/2676
#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		printf("%lld\n", (n-m)*m+1);
	}
	return 0;
}
