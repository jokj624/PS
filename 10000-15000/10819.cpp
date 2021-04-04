//AC
//BOJ 10819 차이를 최대로
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
	int N, ans = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	do{
		int sum = 0;
		for(int i=0; i<v.size()-1; i++){
			sum += abs(v[i]-v[i+1]);
		}
		ans = max(ans, sum);
	}while(next_permutation(v.begin(),v.end()));
	cout << ans;
	return 0;
}