//AC
//BOJ 21870 시철이가 사랑한 GCD
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#define SIZE 200002
using namespace std;
typedef long long ll;
int N;
int room[SIZE];
ll gcd(int x, int y){
	if(y == 0) 	return x;
	else	return gcd(y, x%y);
}
ll all_gcd(int left, int right){
	ll gcd_num = room[left];
	for(int i=left+1; i<=right; i++){
		gcd_num = gcd(gcd_num, room[i]);
	}
	return gcd_num;
}
ll solve(int left, int right){
	if(left > right)	return 0;
	if(left == right)	return room[left];
	int mid;
	if((right-left+1)%2){
		mid = (left+right)/2 - 1;
	}
	else	mid = (left+right)/2;

	ll left_ans = solve(left, mid);
	ll right_ans = solve(mid+1, right);
	ll resL = all_gcd(left, mid);
	ll resR = all_gcd(mid+1, right);
	if(left_ans + resR > right_ans + resL)	return left_ans + resR;
	else return right_ans + resL;
	
}
int main(){
	ll ans = 0;
	cin >> N;
	for(int i=1; i<=N; i++){
		scanf("%d", &room[i]);
	}
	printf("%lld", solve(1, N));
	return 0;
}
