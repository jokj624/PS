//AC
//BOJ 1946 신입 사원 
//https://www.acmicpc.net/problem/1946
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int>& a, pair<int, int>& b){
	return a.first < b.first;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, cnt=1;
		vector<pair<int, int> > v;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int seo, meon;
			scanf("%d %d", &seo, &meon);
			v.push_back(make_pair(seo,meon));
		}
		sort(v.begin(), v.end(), compare);
        int best = v[0].second;
		for(int i=1; i<n; i++){
            if(v[i].second < best){
                cnt++;
                best = v[i].second;
            }
		}
		printf("%d\n", cnt);
	}
}