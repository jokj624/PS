
//AC
//BOJ 9251 LCS
//https://www.acmicpc.net/problem/9251
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[1005][1005];
int main(){
	string a, b;
	int len = 0;
	cin >> a;
	cin >> b;
	for(int i=1; i<=a.size(); i++){
		for(int j=1; j<=b.size(); j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
			len = max(len, dp[i][j]);
		}
	}

	cout << len;
	return 0;
}
