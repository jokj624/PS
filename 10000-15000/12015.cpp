//AC
//BOJ 12015 가장 긴 증가하는 부분 수열 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> lis;
int main(){
	int N, a;
	cin >> N;
	lis.push_back(0);
	for(int i=0; i<N; i++){
		scanf("%d", &a);
		if(lis.back() < a){
			lis.push_back(a);
		}
		else{
			int idx = lower_bound(lis.begin(),lis.end(), a)-lis.begin();
			lis[idx] = a;
		}
	}
	cout << lis.size()-1;
	return 0;
}