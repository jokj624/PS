//AC
//BOJ 2875 대회 or 인턴 
//https://www.acmicpc.net/problem/2875
#include <iostream>
using namespace std;
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int temp_cnt;
	while(k>0){
		if(n/2 > m){
			temp_cnt = n/2 - m; 
			n-=temp_cnt;
			k-=temp_cnt;
		}
		else if(n/2 < m){
			temp_cnt=m-n/2;
			m-=temp_cnt;
			k-=temp_cnt;
		}
		else if(n/2 == m){
			for(int i=1; i<=k; i++){
				if(i%3 == 0){
					m--;
				}
				else{
					n--;
				}
			}
			k=0;
		}
	}
	if(n/2 == m)	printf("%d", m);
	else if(n/2 > m)	printf("%d", m);
	else if(n/2 < m)	printf("%d", n/2);
}
