//AC
//BOJ 2213 트리의 독립집합
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[10001][2];
int weight[10001];
vector<int> v[10001];
vector<int> ans_node;
bool check[10001]={false};

void DP(int child, int root){
	int choice = 0, not_choice=0;
	for(int i=0; i<v[child].size(); i++){
		int sub = v[child][i];
		if(sub == root)	continue;
		DP(sub, child);
		choice += dp[sub][0];
		not_choice += max(dp[sub][0], dp[sub][1]);
	}
	dp[child][1] = choice + weight[child];
	dp[child][0] = not_choice;
//	if(dp[child][1] >= dp[child][0])	ans_node.push_back(child);
}
void addNode(int child, int root){
	if(dp[child][1] > dp[child][0] && !check[root]){
		ans_node.push_back(child);
		check[child] = true;
	}
	for(int sub : v[child]){
		if(sub != root)	addNode(sub, child);
	}
}
int main(){
	int n, a, b, ans=0, ans_n=0;
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d", &weight[i]);
	}	
    while(scanf("%d %d", &a, &b) != EOF){
        v[a].push_back(b);
        v[b].push_back(a);
    } 
   
	DP(1,0);
	ans = max(dp[1][0], dp[1][1]);
	addNode(1,0);
	cout << ans << "\n";
	sort(ans_node.begin(), ans_node.end());
	for(int nd : ans_node){
		printf("%d ", nd);
	}
	return 0;
} 
