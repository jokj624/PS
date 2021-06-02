//AC
//BOJ 21868 미적분학 입문하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
	int e1, e2, a, b, x;
	int imax = pow(10, 8);
	scanf("%d %d", &e1, &e2);
	scanf("%d %d", &a, &b);
	scanf("%d", &x);
	ll L = a*x+b;
	cout << L << "\n";
	if(a == 0){
		printf("0 0");
		return 0;
	}
	else{
		printf("%d %d", e1, e2*abs(a));
	}
	 
	return 0;
}
