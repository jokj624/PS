//AC
//BOJ 19582 200년간 폐관수련했더니 PS 최강자가 된 건에 대하여 
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> con; 
vector<con> v;
int main(){
	int n, cnt = 0, idx = -1, maxIdx = -1;
	ll money, price, sum = 0, maxPrice = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%lld %lld", &money, &price);
		v.push_back({money, price});
	}
	for(int i=0; i<n; i++){
		if(sum <= v[i].first){
			sum += v[i].second;
			cnt += 1;
		} 
		else{
			if(idx == -1)	idx = i;
		}
	}
	if(cnt >= n-1){
		printf("Kkeo-eok");
		return 0;
	}
	cnt = 0;
	sum = 0;
	for(int i=0; i<n; i++){
		if(i == idx)	continue;
		if(sum <= v[i].first){
			sum += v[i].second;
			cnt += 1;
		} 
		if(i < idx){
			if(v[i].second > maxPrice)	{
				maxPrice = v[i].second;
				maxIdx = i;
			}
		}
	}
	if(cnt >= n-1){
		printf("Kkeo-eok");
		return 0;
	}
	cnt = 0;
	sum = 0;
	for(int i=0; i<n; i++){
		if(i == maxIdx)	continue;
		if(sum <= v[i].first){
			sum += v[i].second;
			cnt += 1;
		} 
	}
	if(cnt >= n-1){
		printf("Kkeo-eok");
		return 0;
	} 
	else 	printf("Zzz");
	return 0;
}
