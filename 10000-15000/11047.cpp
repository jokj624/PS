//AC
//BOJ 11047 동전 0
//https://www.acmicpc.net/problem/11047 
#include <iostream>
using namespace std;
int main(){
	int n, k, cnt=0;
	cin >> n >> k;
	int coin[11];
	for(int i=0; i<n; i++){
		cin >> coin[i];
	}
	int temp;
	for(int i=n-1; i>=0; i--){
		if(k >= coin[i]){
			temp = i;
			break;
		}
	}
	if(coin[temp] == k){
		cout << "1";
		return 0;
	}
	for(int i=temp; i>=0; i--){
		cnt += k / coin[i];
		k %= coin[i];
		if(k == 0){
			break;
		}
	}
	cout << cnt;
}
