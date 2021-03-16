//AC
//BOJ 1713 후보 추천하기
//https://www.acmicpc.net/problem/1713
#include <stdio.h>
typedef struct{
	int cnt;
	int order;
	int candidate;
}CAND;
CAND can[22]={0};
int check[101] = {0};
int add(int p, int j);
int new_add(int p);
int che=1, n, num;
int main(){
	int i, p;
	scanf("%d %d", &n, &num);
	for(i=1; i<=num; i++){
		scanf("%d", &p);
		if(check[p])	new_add(p);
		else{
			add(p,i);
		}
	}
	for(i=1; i<=100; i++){
		if(check[i])	printf("%d ", i);
	}
}
int add(int p, int j){
	int min, i, temp=1, min2;
	if(che <= n){
		che++;
		for(i=1; i<=n; i++){
			if(can[i].candidate == 0){
				can[i].candidate = p;
				can[i].cnt++;
				can[i].order = j;
				check[p] = 1;
				break;
			}
		}
	}
	else{
		min = can[1].cnt;
		min2 = can[1].order;
		for(i=2; i<=n; i++){
			if(min > can[i].cnt){
				temp = i;
				min2 = can[i].order;
				min = can[i].cnt;
			}
			else if(min == can[i].cnt){
				if(can[i].order < min2){
					temp = i;
					min2 = can[i].order;
				}
			}
		}
		check[can[temp].candidate] = 0;
		can[temp].candidate = p;
		can[temp].order = j;
		can[temp].cnt = 1;
		check[p] = 1;
		return;
	}
	return;
}
int new_add(int p){
	int i;
	for(i=1; i<=n; i++){
		if(can[i].candidate == p)	{
			can[i].cnt++;
			return;
		}
	}
}

