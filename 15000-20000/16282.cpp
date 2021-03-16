//AC
//BOJ 16282 Black Chain
//https://www.acmicpc.net/problem/16282
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	long long k;
	cin >> k;
	long long n = 1;
	while(1){
		long long tmp;
		tmp = n+(n+1)*((long long)pow(2,n+1)-1);
		if(tmp >= k){
			printf("%lld", n);
			break;
		}
		n++;
	}
	return 0;
}

