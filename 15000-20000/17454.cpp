//AC
//BOJ 17454 갓
//https://www.acmicpc.net/problem/17454

#include <iostream>
using namespace std;
int main(){
	int n;
	int dh, ds, hd, hs, sd, sh;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d %d %d %d %d", &dh, &ds, &hd, &hs, &sd, &sh);
		(sd*hd)>(hs-hd)*(sh-sd) ? printf("GOD\n") : printf("KDH\n");
	}
	return 0;
} 
