//AC
//BOJ 2667 단지번호붙이기 
// https://www.acmicpc.net/problem/2667
#include <stdio.h>
#define MAX_SIZE 630
int search(int v, int e);
int arr[30][30]={0};
int check[MAX_SIZE] = {0};
int n, cnt=0;
int main(){
	int i, j, temp;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%1d", &arr[i][j]);
		}
	}

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(arr[i][j]==1){
				search(i,j);
				cnt++;
			}
		}
	}
	for(i=0; i<cnt; i++){
		for(j=0; j<cnt-1; j++){
			if(check[j]> check[j+1]){
				temp = check[j];
				check[j] = check[j+1];
				check[j+1] = temp;
			}
		}
	}
	printf("%d\n",cnt);
	for(i=0; i<cnt; i++) 	printf("%d\n", check[i]);
 	return 0;
}
int search(int v, int e){
	if(arr[v][e-1] == 1){
		check[cnt]++;
		arr[v][e-1]=2;
		search(v, e-1);
	}
	if(arr[v][e+1] == 1){
		check[cnt]++;
		arr[v][e+1]=2;
		search(v, e+1);
	}
	if(arr[v-1][e] == 1){
		check[cnt]++;
		arr[v-1][e]=2;
		search(v-1,e);
	}
	if(arr[v+1][e] == 1){
		check[cnt]++;
		arr[v+1][e]=2;
		search(v+1,e);
	}
	if(arr[v][e] == 1) 	check[cnt]++;
	return;
}

