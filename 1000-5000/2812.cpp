//AC
//BOJ 2812 크게 만들기
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int num[500001] = {0};
deque<int> dq;
int main(){
	int n, k, idx;
	scanf("%d %d", &n, &k);
	string str;
	cin >> str;
	for(int i=0; i<n; i++){
		num[i] = str[i] - '0';
	}
	for(int i=0; i<n; i++){
		while(!dq.empty() && k && dq.back()<num[i]){
			dq.pop_back();
			k--;
		}
		dq.push_back(num[i]);
		
	}

	for(int i=0; i<dq.size()-k; i++){
		printf("%d", dq[i]);
	}
	return 0;
}