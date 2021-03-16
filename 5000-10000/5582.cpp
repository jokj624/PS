//AC
//BOJ 5582 공통 부분 문자열 
//https://www.acmicpc.net/problem/5582  

#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;
int dp[4001][4001];
int main(){
	string s, s2;
	int max_len = 0;
	cin >> s;
	cin >> s2;
	int len1 = s.size();
	int len2 = s2.size();
	for(int i=0; i<len2; i++){
		if(s[0]==s2[i]){
			dp[0][i] = 1;
		}
	}
	for(int i=0; i<len1; i++){
		if(s[i]==s2[0]){
			dp[i][0] = 1;
		}
	}
	for(int i=1; i<len1; i++){
		for(int j=1; j<len2; j++){
			if(s[i]==s2[j]){
				dp[i][j] = dp[i-1][j-1]+1;
			}

			max_len = max(max_len, dp[i][j]);
		}
	}

	printf("%d", max_len);
	return 0;
} 
