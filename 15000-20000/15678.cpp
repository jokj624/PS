//AC
//BOJ 15678 연세 워터파크

#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<long long int> v;
long long int E[101010];
deque<pair<long long int, long long int> > d;
long long int max_l(long long int a, long long int b){
	return a >= b ? a : b;
}
int main(){
	int N, D;
	long long int a, ans;
	cin >> N >> D;
	for(int i=0; i<N; i++){
		scanf("%lld", &a);
		v.push_back(a);
	}
	ans = v[0];
	for(int i=0; i<N; i++){
		while(!d.empty() && d.front().second < i-D){
			d.pop_front();
		}
		E[i] = v[i];
		if(!d.empty())	E[i] = max(E[i], d.front().first+v[i]);
		while(!d.empty() && d.back().first <= E[i]){
			d.pop_back();
		}
		ans = max_l(ans, E[i]);
		d.push_back({E[i], i});
	}
	cout << ans;
	return 0;
}