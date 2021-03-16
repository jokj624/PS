//AC
//BOJ 17827 달팽이 리스트
////https://www.acmicpc.net/problem/17827 
#include <iostream>
#include <vector>
using namespace std;
int arr[200001];
int main(){
	int n, m, v, a, temp;
	bool min = false;
	cin >> n >> m >> v;
	cin >> a;
	arr[0] = a;
	for(int i=1; i<n; i++){
		scanf("%d", &arr[i]);
	}
	arr[n] = arr[v-1];
	temp = n-(v-1);
	if(arr[n]==arr[n-1]){
		min = true;
	}
	for(int i=0; i<m; i++){
		scanf("%d", &a);
		if(a>=1 && a<=n){
			printf("%d\n", arr[a]);
		}
		else{
			if(min){
				printf("%d\n", arr[n]);
			}
			else{
				if((a%temp)<v){
					printf("%d\n",arr[(a%temp)+temp]);
				}
				else	printf("%d\n", arr[a%temp]);
			}
		}
	}
	return 0;
	
}
