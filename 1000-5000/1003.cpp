//AC
//BOJ 1003 피보나치 함수 
// https://www.acmicpc.net/problem/1003
#include <iostream>
using namespace std;
void fibo(int n) {
	int dp1[42];
	int dp2[42];
	dp1[0] = 1;
	dp2[0] = 0;
	dp1[1] = 0;
	dp2[1] = 1;
	for (int i = 2; i <= 40; i++) {
		dp1[i] = dp1[i - 1] + dp1[i - 2];
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}
	cout << dp1[n] << " " << dp2[n] << endl;
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		fibo(n);
	}
}
