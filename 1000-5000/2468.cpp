//AC
//BOJ 2468 안전 영역 
// https://www.acmicpc.net/problem/2468
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[101][101];
int cnt[101]={0};
int n;
bool check[101][101]={false};
void dfs(int x, int y, int rain){
	check[x][y] = true;
	if(x+1<n && x+1>=0 && check[x+1][y] == false && arr[x+1][y] > rain){
		dfs(x+1,y,rain);
	}
	if(x-1>=0 && x-1<n && check[x-1][y] == false && arr[x-1][y] > rain){
		dfs(x-1,y,rain);
	}
	if(y+1<n && y+1>=0 && check[x][y+1] == false && arr[x][y+1] > rain){
		dfs(x,y+1,rain);
	}
	if(y-1 >= 0 && y-1 < n && check[x][y-1] == false && arr[x][y-1] > rain){
		dfs(x,y-1,rain);
	}
}
int main(){
	cin >> n;
	int s=200,m=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &arr[i][j]);
			s=min(arr[i][j], s);
			m=max(arr[i][j], m);
		}
	}
	int max2=0;
	for(int k=s; k<=m; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(check[i][j] == false && arr[i][j]>k){
					dfs(i,j,k);
					cnt[k]++;
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				check[i][j] = false;
			}
		}
		max2 = max(cnt[k],max2);
	}
	if(max2 == 0)	printf("1");
	else{
		printf("%d",max2);
	}
}
