//AC
//BOJ 17521 Byte Coin
//https://www.acmicpc.net/problem/17521

#include <iostream>
using namespace std;
int main() {
	long long n, coin=0;
	long long money;
	int arr[16];
	bool check = false;
	cin >> n >> money;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < arr[i + 1] && check == false) {
			coin += (money / arr[i]);
			money = (money%arr[i]);
			check = true;
		}
		else if (arr[i] > arr[i + 1] && check == true) {
			money += (arr[i] * coin);
			coin = 0;
			check = false;
		}
	}
	money += (arr[n - 1] * coin);
	cout << money;
}
