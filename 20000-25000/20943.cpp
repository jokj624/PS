//AC
//BOJ 20943 카카오톡
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9876543210
using namespace std;
vector<double> v;
vector<int> cnt;
int main(){
	int N, count = 1, a, b, c, total = 0;
	long long int ans = 0;
	double tmp;
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(b==0){
			v.push_back(MAX);
			continue;
		}
		tmp = (double)a/b;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N-1; i++){
		if(v[i] == v[i+1]){
			count+=1;
		}
		else{
			cnt.push_back(count);
			total += count;
			count = 1;
		}	
		if(i == N-2){
			total += count;
			cnt.push_back(count);
		}
	}
	for(int i=0; i<cnt.size(); i++){
		ans += cnt[i] * (total-cnt[i]);
	}
	cout << ans/2;
	return 0;
}
