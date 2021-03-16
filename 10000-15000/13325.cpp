//AC
//BOJ 13325 이진 트리 
//https://www.acmicpc.net/problem/13325 
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long dp[210000];
long long sum;
int size;
long long tree(int idx){
	if(idx*2 >= size){
		sum += dp[idx];
		return dp[idx];
	}
	else{
		int left = tree(2*idx);
		int right = tree(2*idx+1);
		sum += (dp[idx]+abs(left-right));
		return dp[idx]+max(left, right);
	}
}
int main(){
	int k;
	scanf("%d", &k);
    size = pow(2, k + 1);
    dp[1] = 0;
    for (int i = 2; i < size; i++) {
       scanf("%d", &dp[i]);
    }
    tree(1);
    printf("%lld", sum);
    return 0;
}
