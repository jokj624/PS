//AC
//BOJ 7568 덩치
//https://www.acmicpc.net/problem/7568 
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main(){
	int n, cnt=0;
	vector<pair<int, int> > dung;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		dung.push_back(make_pair(a,b));
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(dung[i].first < dung[j].first && i!=j){
				if(dung[i].second < dung[j].second){
					cnt++;
				}
			}
		}
		printf("%d ", cnt+1);
		cnt=0;
	}
	return 0;
}
