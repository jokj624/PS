//AC
//BOJ 7344 나무 막대
//https://www.acmicpc.net/problem/7344
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
vector<pair<int, int> > v;
bool visit[5001];
int main(){
	int t, ans = 0;
	cin >> t;
	while(t--){
		v.clear();
		memset(visit, false, sizeof(visit));
		int n, ans = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a,b));
		}
		sort(v.begin(), v.end());
		int current;
		for(int i=0; i<n; i++){
			if(visit[i])	continue;
			visit[i] = true;
			current = v[i].second;
			ans+=1;
			for(int j=i+1; j<n; j++){
				if(!visit[j]&&v[j].second >= current){
					visit[j] = true;
					current = v[j].second;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
