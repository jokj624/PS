//AC
//BOJ 14754	Pizza Boxes
//https://www.acmicpc.net/problem/14754
#include <iostream>
#include <algorithm>
using namespace std;
long long max_c[1001];
long long max_r[1001];
bool check[1001][1001];
int pizza[1001][1001];
int main(){
	int n, m, ri=1, rj=1, ci=1, cj=1;
	long long sum = 0, t;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
		    cin >> pizza[i][j];
			sum += pizza[i][j];
			if(max_r[i]<pizza[i][j]){
				max_r[i] = pizza[i][j];
				ri = i; rj = j;
			}
		}
		check[ri][rj] = true;
        sum -= max_r[i];
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(max_c[i] < pizza[j][i]){
				max_c[i] = pizza[j][i];
				ci=i; 	cj=j;
			}
		}
		if(check[cj][ci])	max_c[i] = 0;
	    sum -= max_c[i]; 
    }
	printf("%lld", sum);
    return 0;
} 
