//AC
//BOJ 15366 Olivander
//https://www.acmicpc.net/problem/15366
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, temp;
	vector<int> x;
	vector<int> y;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &temp);
		x.push_back(temp);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &temp);
		y.push_back(temp);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for(int i=0; i<n; i++){
		if(x[i]>y[i]){
			printf("NE");
			return 0;
		}
	}
	printf("DA");
	return 0;
}
