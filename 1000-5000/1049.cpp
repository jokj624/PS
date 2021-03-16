//AC
//BOJ 1049 기타줄 
//https://www.acmicpc.net/problem/1049 
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, m, price=100000000, temp;
	int pack[51], one[51];
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &pack[i], &one[i]);
	}
	sort(pack, pack+m);
	sort(one, one+m);
	if(n > 6){
		int d = n/6;
		int one_temp = n - 6*d;
		temp = pack[0] * d + one[0]*one_temp;
		price = min(temp, price);
		
	}
	temp = one[0] * n;
	price = min(temp, price);
	temp = pack[0]*(n/6+1);
	price = min(temp, price);
	cout << price;
	return 0;
}
