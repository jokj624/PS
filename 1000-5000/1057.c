//AC
//BOJ 1057 토너먼트
//https://www.acmicpc.net/problem/1057
#include <stdio.h>
int main(){
	int n, kim, im;
	int cnt = 0;
	scanf("%d %d %d", &n, &kim, &im);
	
	while(kim != im){
		kim = kim/2 + kim%2;
		im = im/2 + im%2;
		cnt++;
	}
	if(cnt == 0)	printf("-1");
	else	printf("%d\n", cnt);
}
