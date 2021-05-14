//AC
//BOJ 2470 나무자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> v;
int main(){
	int N, ans1, ans2, tmp;
	ll sum = 2e9+1;
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N; i++){
		int left = i + 1;
		int right = N-1;
		while(left <= right){
			int mid = (left+right) / 2;
			if(sum > abs(v[i] + v[mid])){
				sum = abs(v[i] + v[mid]);
				ans1 = v[i];
				ans2 = v[mid];
			}
			if(v[i] + v[mid] < 0) 	left = mid + 1;
			else	right = mid - 1;
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
