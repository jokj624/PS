//AC
//#661 Div 3
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, ans=0;
		int arr[51]={0};
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		int mid, l, r, cnt;
		for(int i=n-1; i>0; i--){
			for(int j=0; j<n-1; j++){
				mid = arr[j]+arr[i];
				cnt=1;
				l=j+1; 	r=i-1;
				while(l<r){
					if(arr[l]+arr[r]==mid){
						l++;	r--;
						cnt++;
					}
					else if(arr[l]+arr[r]>mid){
						r--;
					}
					else if(arr[l]+arr[r]<mid){
						l++;
					}
				}
				ans = max(ans, cnt);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
