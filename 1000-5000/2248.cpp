//AC
//BOJ 2248 이진수찾기 
#include <iostream>
#include <string>
using namespace std;
long long dp[33][33];
string ans;
void binary(int N, int L, long long l){
	long long cnt = 0;
	if(N==0){
		return;
	}
	if(L==0){
		for(int i=0; i<N; i++){
			ans += '0';
		}
		return;
	}
	for(int i=0; i<=L; i++){
		cnt += dp[N-1][i];
	}
	if(cnt >= l){
		ans+='0';
		binary(N-1, L, l);
	}
	else{
		ans+='1';
		l -= cnt;
		binary(N-1, L-1, l);
	}
}
int main(){
	int N, L;
	long long l;
	cin >> N >> L >> l;
	dp[0][0] = 1;
	for(int i=1; i<33; i++){
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for(int i=2; i<=N; i++){
		for(int j=1; j<=i; j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
		}
	}
	binary(N, L, l);
	cout << ans;
	return 0;
} 
