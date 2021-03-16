//AC
//BOJ 2110 공유기 설치 
//https://www.acmicpc.net/problem/2110 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,c;
vector<int> v;
bool check(long long x){
	int temp = 1;
	int t=v[0];
	for(int i=0; i<n; i++){
		if(v[i]-t >= x){
			t = v[i];
			temp++;
		}
	}
	if(temp >= c)	return true;
	else	return false;
}
int main(){
	int m;
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%d", &m);
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	long long mid, l=1, r, ans=0;
	r = v[n-1]-v[0];
	while(l<=r){
		mid = (l+r)/2;
		if(check(mid)){
			l = mid+1;
			if(ans < mid){
				ans = mid;
			}
		}
		else{
			r = mid - 1;
		}
	}
	printf("%lld", ans);
	return 0;
}
