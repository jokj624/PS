//AC
//BOJ 15513 Lottery for Vitcoins at Moloco (Hard)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct vitcoin{
	int w,q,idx;
};
vector<vitcoin> v;
bool cmp(const vitcoin &v1, const vitcoin &v2){
	double ans1, ans2;
	ans1 = v1.w*(10000-v2.q);
	ans2 = v2.w*(10000-v1.q);
	if(ans1 == ans2)	return v1.idx < v2.idx;
	return ans1 > ans2;
}
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %lf", &a, &b);
		v.push_back({a,b,i+1});
	}
    sort(v.begin(), v.end(), cmp);
	for(vitcoin coin : v){
		printf("%d ", coin.idx);
	}
	return 0;
}