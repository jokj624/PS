//AC
//BOJ 3020 개똥벌레 
//https://www.acmicpc.net/problem/3020 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, h;
int d[500001];
int s[500001];
int main(){
	scanf("%d %d", &n, &h);
	vector<int> ans;
	for(int i=0; i<n/2; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		d[a]++;
		s[h-b+1]++;
	}
	for(int i=h; i>1; i--){
		d[i-1] += d[i];
	}
	for(int i=1; i<h; i++){
		s[i+1]+= s[i];
	}
	for(int i=1; i<=h; i++){
		ans.push_back(s[i]+d[i]);
	}
	sort(ans.begin(),ans.end());
	int a = 1, cnt=1;
	while(a < h){
		if(ans[0] == ans[a]){
			cnt++;
		}
		a++;
	}
	printf("%d %d", ans[0], cnt);
}
