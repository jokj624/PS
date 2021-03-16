//AC
//#661 Div 3
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	int n;
	while(t--){
		int arr[51]={0};
		int cnt=0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n+1);
		for(int i=1; i<=n; i++){
			if(arr[i]==0)	continue;
			for(int j=i+1; j<=n; j++){
				if(arr[j]==0)	continue;
				if(abs(arr[i]-arr[j])<=1){
					if(arr[i]==arr[j]){
						arr[j]=0;
					}
					else if(arr[i]<arr[j]){
						arr[i] = 0;
					}
					else if(arr[i]>arr[j]){
						arr[j] = 0;
					}
				}	
			}
		}
		for(int i=1; i<=n; i++){
			if(arr[i]!=0)	cnt++;
		}
		cnt==1 ? printf("YES\n"):printf("NO\n");
	}
	return 0;
}
