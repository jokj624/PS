//AC
//BOJ 11062 카드게임
// https://www.acmicpc.net/problem/11062
#include <iostream>
#include <algorithm>
using namespace std;
int card[1001];
int dp[1001][1001][2];
int game(int s, int e, int flag){
	int &r = dp[s][e][flag];
	if(r!=-1){
		return r; 
	}
	if(s>=e){
		if(flag)	return r = card[s];
		else	return r=0;
	}
	if(flag){
		r= max(game(s+1, e, !flag)+card[s],game(s,e-1,!flag)+card[e]);
	}
	else{
		r=min(game(s+1,e,!flag), game(s,e-1,!flag));
	}
	return r;
}
int main(){
	int n,t;
	cin >> t;
	while(t--){
		int ans = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &card[i]);
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<2; k++){
					dp[i][j][k] = -1;
				}
			}
		}
		ans += game(0,n-1,1);
		printf("%d\n", ans);
	}
	return 0;
}
