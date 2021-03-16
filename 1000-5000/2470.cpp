//AC
//BOJ 2471 두 용액
// https://www.acmicpc.net/problem/2470
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
vector<long long> v;
int main(){
	int n, a, b;
	long long d = LLONG_MAX;
	cin >> n;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int l=0, r=n-1;
	while(l<r){
		if(v[l]+v[r] == 0){
			printf("%lld %lld", v[l], v[r]);
			return 0;
		}
		else if(v[l]+v[r]<0){
			if(abs((v[l]+v[r])-0)<d){
				a=l; 	b=r;
				d=abs((v[l]+v[r])-0);
			}
			l++;
		}
		else{
			if(abs((v[l]+v[r])-0)<d){
				a=l; 	b=r;
				d=abs((v[l]+v[r])-0);
			}			
			r--;
		}
	}
	printf("%lld %lld", v[a], v[b]);
	return 0;
}

