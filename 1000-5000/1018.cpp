//AC
//BOJ 1018 u???? ??? ????
//https://www.acmicpc.net/problem/1018 

?#include <iostream>
#include <algorithm>
using namespace std;
char chess[52][52];
int n, m; 
int check_b(int x, int y){
	int cnt=0;
	if(x+8 > n || y+8 > m){
		return 1000000000;
	}
	for(int i=x; i<x+8; i++){
		for(int j=y; j<y+8; j++){
			if(!(i%2)){
				if(!(j%2)){
					if(chess[i][j] != 'B')	cnt++;
				}
				else{
					if(chess[i][j] != 'W')	cnt++;
				}
			}
			else{
				if(!(j%2)){
					if(chess[i][j] !='W')	cnt++;
				}
				else{
					if(chess[i][j] != 'B')	cnt++;
				}
			}
		}
	}
	return cnt;
}
int check_w(int x, int y){
	int cnt=0;
	if(x+8 > n || y+8 > m){
		return 1000000000;
	}
	for(int i=x; i<x+8; i++){
		for(int j=y; j<y+8; j++){
			if(!(i%2)){
				if(!(j%2)){
					if(chess[i][j] != 'W')	cnt++;
				}
				else{
					if(chess[i][j] != 'B')	cnt++;
				}
			}
			else{
				if(!(j%2)){
					if(chess[i][j] !='B')	cnt++;
				}
				else{
					if(chess[i][j] != 'W')	cnt++;
				}
			}
		}
	}
	return cnt;
}
int main(){
	int a, b, result=1000000000, temp;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%s", chess[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			a = check_b(i,j);
			b = check_w(i,j);
			temp = min(a,b);
			result = min(temp, result);
		}
	}
	printf("%d", result);
	return 0;
}
