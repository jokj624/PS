//AC
//BOJ 2309 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> combination = {0, 0, 1, 1, 1, 1, 1, 1, 1};
int main(){
	int t;
	for(int i=0; i<9; i++){
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	do{
		int sum = 0, idx = 0;
		int ans[7]; 
		for(int i=0; i<9; i++){
			if(combination[i]==1){
				sum += v[i];
				ans[idx++] = v[i];
			}
		}
		if(sum==100){
			for(int i=0; i<7; i++){
				cout << ans[i] << "\n";
			}
			break;
		}
	} while(next_permutation(combination.begin(), combination.end()));
	return 0;
}