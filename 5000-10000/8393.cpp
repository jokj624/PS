//AC
//BOJ 8393  합    
//https://www.acmicpc.net/problem/8393 
#include <iostream>
using namespace std;
int main(){
	int t;
	long long ans = 0;
	cin >> t;
	for(int i=1; i<=t; i++){
		ans += i;
	}
	cout << ans;
	return 0;
} 
