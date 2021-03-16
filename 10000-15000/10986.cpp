//AC
//BOJ 10986 나머지 합
// https://www.acmicpc.net/problem/10986

#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main(){
	int n, m,s=0;
	cin >> n >> m;
	vector<long long> cnt(m,0); 
	for(int i=0; i<n; i++){
		int a;
		scanf("%d" ,&a);
		v.push_back(a%m);
	}
	cnt[0] = 1;
	for(int i=0; i<n; i++){
		s+=v[i];
		s%=m;
		cnt[s] += 1;
	}
	long long ans=0;
	for(int i=0; i<m; i++){
		long long temp = cnt[i];
		ans += temp*(temp-1)/2;
	}
	printf("%lld", ans);
	return 0;
} 
