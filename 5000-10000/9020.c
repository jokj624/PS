//AC
//BOJ 9020 골드바흐의 추측 
//https://www.acmicpc.net/problem/9020 
#include <stdio.h>
#include <math.h>
int p[10000]={0};
void gold(int num){
	int i, tempa, tempb, flag = 0;
	int min = 2147483646;
	for(i=2; i<num; i++){
		if(p[i] == -1 || p[num-i]==-1){
			continue;
		}
		else if(p[i] == 1 && p[num-i] == 1){
			flag = 1;
		}
		else if(p[i] == 0 && p[num-i] == 1){
			check(i);
			if(p[i] == 1)	flag =1;
		}
		else if(p[i] == 1 && p[num-i] == 0){
			check(num-i);
			if(p[num-i] ==1)	flag = 1;	
		}
		else if(p[i] == 0 && p[num-i] == 0){
			check(i);
			check(num-i);
			if(p[i]==1 && p[num-i] == 1)	flag=1;
		}
		if(flag){
			if(abs(i-(num-i)) < min){
				tempa = i;
				tempb = (num-i);
				min = abs(i-(num-i));
			}
		}
		flag=0;
	}
	printf("%d %d\n", tempa, tempb);
}
void check(int n){
	int i=0;
	for(i=2; i<n; i++){
		if(!(n%i))	{
			p[n] = -1;
			return;
		}	
	}
	p[n] = 1;
}
int main(){
	int t, i, num;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d", &num);
		gold(num);
	}
	return 0;
}
