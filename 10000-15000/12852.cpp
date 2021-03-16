//AC
//BOJ 12852 1로 만들기 2 
#include <iostream>
#define MAX 987654321
using namespace std;
int dp[1000001];
int main(){
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2; i<=n; i++){
		dp[i] = MAX;
		if(!(i%3)){
			dp[i] = min(dp[i/3], dp[i-1]);
		}
		if(!(i%2)){
			dp[i] = min(dp[i],min(dp[i/2], dp[i-1]));
		}
		dp[i] = min(dp[i],dp[i-1]);
		dp[i] += 1;
	}
	int tmp = dp[n], idx = n;
	cout << dp[n] << "\n";
	while(idx > 0){
		cout << idx << " ";
		if(idx == 1)	break;
		tmp -= 1;
		if(!(idx%3)&&tmp == dp[idx/3]){
			idx /= 3; 
		}
		else if(!(idx%2)&&tmp == dp[idx/2]){
			idx /= 2; 
		}
		else if(tmp == dp[idx-1]){
			idx -= 1; 
		}
	}
	return 0;
}