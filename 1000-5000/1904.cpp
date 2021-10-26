//AC
//BOJ 1904 01타일
#include <iostream>
using namespace std;
int main() {
	long long v[1000001] = {0};
	int n;
	cin >> n;
	v[1] = 1;
	v[2] = 2;
	for (int i = 3; i <= n; i++) {
		v[i] = (v[i - 1]+ v[i-2]) % 15746;
	}
	
	cout << v[n]<< endl;
}
