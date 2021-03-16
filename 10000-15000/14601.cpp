//AC
//BOJ 14601 샤워실 바닥 깔기(Large)
#include <iostream>
#include <cmath>
using namespace std;
int arr[130][130];
int K, cnt = 0;
int mat(int sx, int a, int b){
	for(int i=a; i<a+sx; i++){
		for(int j=b; j<b+sx; j++){
			if(arr[i][j] != 0)	return -1;
		}
	}
	return 1;
}
void solve(int sx, int a, int b){
	int half = sx / 2;
	cnt += 1;
	if(mat(half, a, b)==1) 	arr[a+half-1][b+half-1] = cnt; 
	if(mat(half, a+half, b)==1) 	arr[a+half][b+half-1] = cnt;
	if(mat(half, a, b+half)==1) 	arr[a+half-1][b+half] = cnt;
	if(mat(half, a+half, b+half)==1) 	arr[a+half][b+half] = cnt; 
	if(half <= 1)	return;  //최소 분할됨  
	  
	solve(half, a, b);	
	solve(half, a+half, b);
	solve(half, a, b+half);
	solve(half, a+half, b+half);   //4분할 
	
}
int main(){
	int x, y, two;
	cin >> K >> x >> y;
	arr[x][y] = -1;
	two = pow(2, K);
	solve(two, 1,1);
	for(int i=two; i>=1; i--){
		for(int j=1; j<=two; j++){
			printf("%d ", arr[j][i]);
		} printf("\n");
	} 
	return 0;
}