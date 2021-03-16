//AC
//BOJ 2163 초콜릿 자르기
//https://www.acmicpc.net/problem/2163 
#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	cout << m - 1 + (n - 1)*m;
}
