//AC
//BOJ 20953 고고학자 예린
#include <iostream>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int a, b;
		scanf("%d %d", &a, &b);
		long long int ans;
		long long int power = (a+b)*(a+b);
		long long int tmp = power * (a+b-1);
		ans = tmp/2;
		printf("%lld\n", ans);
	}
	return 0;
}