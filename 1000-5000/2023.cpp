//AC
//BOJ 2023 신기한 소수
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int pr[5] = {1, 3, 5, 7, 9};
int prime(int num){
	if(num == 1)	return 0;
	else if(num == 2)	return 1;
	for(int i=2; i<=sqrt(num); i++){
		if(!(num % i))	return 0;
	}
	return 1;
}
void dfs(int x, int N){
	if(N==1){
		printf("%d\n", x);
		return;
	}
	for(int i=0; i<5; i++){
		int next = x * 10 + pr[i];
		if(prime(next)){
			dfs(next, N-1);
		}
	}
}
int main(){
	int N;
	cin >> N;
	dfs(2, N);
	dfs(3, N);
	dfs(5, N);
	dfs(7, N);
	return 0;
}
