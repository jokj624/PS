//AC
//BOJ 9252 LCS2
#include <iostream>
#include <string>
using namespace std;
int dp[1002][1002];
int main(){
	string s, t, lcs;
	int ans = 0;
	cin >> s >> t;
	for(int i=1; i<=t.length(); i++){
		for(int j=1; j<=s.length(); j++){
			if(s[j-1] == t[i-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	ans = dp[t.length()][s.length()];
	if(ans == 0){
		cout << ans;
		return 0;
	}

	int p=s.length(), q = t.length();
	int cnt = ans;
	while(cnt>0){
		if(s[p-1] == t[q-1]){
			lcs.push_back(t[q-1]);
			p--;	q--;
			cnt--;	
		}
		else{
			if(dp[q][p] == dp[q][p-1]){
				p--;
			}
			else if(dp[q][p] == dp[q-1][p]){
				q--;
			}
		}
	}
	cout << ans << "\n";
	for(int i=lcs.length()-1; i>=0; i--){
		cout << lcs[i];
	}
	return 0;
}
