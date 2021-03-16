//AC
//BOJ 2098 외판원 순회
#include <iostream>
#define INF 987654321
using namespace std;
int w[17][17], dp[1<<17][17];
int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &w[i][j]);
		}
	}
	for(int i=0; i < 1<<N; i++){
		fill(dp[i], dp[i]+N, INF);
	}
	dp[1][0] = 0;
	for(int vst=0; vst < 1<<N; vst++){
		for(int i=0; i<N; i++){
			//i번째 도시가 vst 집합에 있는지
			if((vst >> i & 1) == 0)	continue;
			for(int j=0; j<N; j++){
				//j에서 i로 가는 길 있는지, vst 안에 j 있는지 확인
				if(w[j][i] == 0 || (vst >> j & 1) == 0)	continue;
				dp[vst][i] = min(dp[vst - (1<<i)][j]+w[j][i] , dp[vst][i]);
			}
		}
	}
	int ans = INF;
	for(int i=0; i<N; i++){
		//0->i번 도시, i->0번 도시 경로 검사
		if(dp[(1<<N)-1][i] == INF || w[i][0]==0)	continue;
		ans = min(ans, dp[(1<<N)-1][i]+w[i][0]);
	}
	cout << ans;
	return 0;
}