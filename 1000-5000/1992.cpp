//AC
//BOJ 1992 쿼드 트리
//https://www.acmicpc.net/problem/1992
#include <iostream>
using namespace std;
void solve(int x, int y, int n);
bool same(int x, int y, int n);
int a[65][65];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &a[i][j]);
		}
	}
	solve(0, 0, n);
	
}
bool same(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (a[i][j] != a[x][y])	return false;
		}
	}
	return true;
}
void solve(int x, int y, int n) {
	if (same(x, y, n)) { cout << a[x][y]; return; }
	cout << "(";
	int m = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solve(x + i * m, y + j * m, m);
		}
	}
	cout << ")";
}
