//AC
//BOJ 5671 호텔 방 번호
//https://www.acmicpc.net/problem/5671 
#include <stdio.h>
int main(){
	int n, m, i, cnt=0, a,b,c,d;
	while(scanf("%d %d", &n, &m)!=EOF){
		for(i=n; i<=m; i++){
			a = i / 1000;
			if(a==0) 	a+=1000;
			b = (i % 1000)/100;
			if(a==1000 && b==0) 	b+=100;
			c = ((i % 1000) % 100) / 10;
			if(a==1000&&b==100&&c==0) 	c+=10;
			d = ((i%1000)%100)%10;
			if(a == b || a == c || a == d || b == c||b == d||c == d) 	continue;
			else 	cnt++;
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}
