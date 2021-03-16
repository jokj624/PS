//AC
//BOJ 2618 경찰차 
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 1001
using namespace std;
int dp[MAX][MAX];
int n, w;
vector<pair<int, int> > v[2];
int dpTable(int a, int b){
	int dis1, dis2, next;
	if(dp[a][b] > 0)	return dp[a][b];
	if(a==w || b==w)	return 0;
	next = max(a, b) + 1;
	dis1 = abs(v[0][next].first-v[0][a].first)+
			abs(v[0][next].second-v[0][a].second);
	dis2 = abs(v[1][next].first-v[1][b].first)+
			abs(v[1][next].second-v[1][b].second);
	
	dp[a][b] = min(dpTable(next,b)+dis1, 
				dpTable(a,next)+dis2);
	return dp[a][b];
}
void printPolice(int a, int b){
	int dis1, dis2, next;
	if(a==w || b==w)	return;
	next = max(a,b)+1;
	dis1 = abs(v[0][next].first-v[0][a].first)+
			abs(v[0][next].second-v[0][a].second);
	dis2 = abs(v[1][next].first-v[1][b].first)+
			abs(v[1][next].second-v[1][b].second);
	if(dp[a][b] == dp[next][b]+dis1){
		printf("1\n");
		printPolice(next, b);
	}
	else{
		printf("2\n");
		printPolice(a,next);
	}
}
int main(){
	int ans = 0;
	vector<int> police;
	cin >> n >> w;
	v[0].push_back({1,1});
	v[1].push_back({n,n});
	for(int i=0; i<w; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[0].push_back({a,b});
		v[1].push_back({a,b});
	}
	cout << dpTable(0,0) << "\n";
	printPolice(0,0);
	return 0;
} 
