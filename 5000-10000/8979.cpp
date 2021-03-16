//AC
//BOJ 8979 올림픽 
//https://www.acmicpc.net/problem/8979 
#include <iostream>
#include <vector>
using namespace std;
vector<int> medal[1000];
bool check[1001]={false};
void check_rank(int n, int k){
	int cnt = 0;
	for(int j=0; j<3; j++){
		for(int i=1; i<=n; i++){
			if(i==k)	continue;
			if(check[i] == false){
				if(medal[k][j] < medal[i][j])	{
					cnt++;
					check[i] = true;
				}
				else if(medal[k][j] > medal[i][j]){
					check[i] = true;
				}
			}
		}
	}
	cnt++;
	printf("%d", cnt);
}
int main(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		int country, gold, silver, bronze;
		cin >> country;
		cin >> gold >> silver >> bronze;
		medal[country].push_back(gold);
		medal[country].push_back(silver);
		medal[country].push_back(bronze);
	}
	check_rank(n,k);
	return 0;
}
