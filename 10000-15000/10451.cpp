//AC
//BOJ 10451 순열 사이클
//https://www.acmicpc.net/problem/10451 
#include <iostream>
using namespace std;
int a[1003];
bool b[1003] = {};
void check(int n);
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (b[i] == false) { 
				check(i); 
				cnt++; 
			}
		}
		cout << cnt << endl;
		for (int i = 1; i <= n; i++) {
			b[i] = false;
		}
	}
	return 0;
}
void check(int n) {
	b[n] = true;
	if (b[a[n]] == false)	check(a[n]);
	else	return;
}
