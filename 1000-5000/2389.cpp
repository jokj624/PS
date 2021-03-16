//AC
//BOJ 2389 세상의 중심에서 ...
//https://www.acmicpc.net/problem/2389 
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double distance(double a, double b){
	return a*a+b*b;
}
int main(){
	int n;
	scanf("%d", &n);
	double a[101];
	double b[101];
	double x=0, y=0;
	for(int i=0; i<n; i++){
		scanf("%lf %lf", &a[i], &b[i]);
		x+= a[i];
		y+= b[i];
	}
	x = x/n;
	y = y/n;
	
	double P = 0.1, d,e,f,j;
	for (int i = 0; i < 30000; i++) {
		int f = 0;
		d = distance(x - a[0], y - b[0]);
		for (int j = 1; j < n; j++) {
			e = distance(x - a[j], y - b[j]);
			if (d < e) { d = e; f = j; }
		}
		x += (a[f] - x)*P;
		y += (b[f] - y)*P;
		P *= 0.999;
	}
	printf("%.10f %.10f ",x,y);
	printf("%.10f", sqrt(d));
	return 0;
}
