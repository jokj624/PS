//AC
//BOJ 2609 최대공약수와 최소공배수  
// https://www.acmicpc.net/problem/2609
#include <stdio.h>
int div(int x, int y);
int mul(int x, int y);
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d", div(a, b),mul(a,b));
	return 0;
}
int div(int x, int y) {
	if (y != 0)	div(y, x%y);
	else	return x;
}
int mul(int x, int y) {
	int div1,p,q;
	div1 = div(x, y);
	p = x/div1;
	q = y/div1;
	return (div1 * p*q);
}
