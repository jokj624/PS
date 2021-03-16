//AC
//BOJ 20949 효정과 새 모니터

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<pair<long long, int> > monitor;
bool cmp(const pair<long long ,int> &a, const pair<long long , int> &b){
	return a.first > b.first;
}
int main(){
	int N;
	long long w, h;
	cin >> N;
	for(int i=1; i<=N; i++){
		scanf("%d %d", &w, &h);
		long long ppi = w*w+h*h;
		monitor.push_back({ppi, i});
	}
	stable_sort(monitor.begin(), monitor.end(), cmp);
	for(pair<long long, int> tmp : monitor){
		printf("%d\n", tmp.second);
	}
	return 0;
}