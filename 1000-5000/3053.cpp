//AC
//BOJ 3053 택시 기하학
//https://www.acmicpc.net/problem/3053
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double r;
	double pi = 3.14159265359; 
	cin >> r;
	double uc;
	uc = pi * pow(r,2);
	printf("%f\n", uc);
	printf("%f", 2*pow(r,2));
	return 0;
}
