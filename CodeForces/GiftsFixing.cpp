//AC
//#661 Div 3
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		long long cnt = 0, min_c=LLONG_MAX, min_o=LLONG_MAX;
		long long candy[51]={0};
		long long orange[51]={0};
		scanf("%d", &n);
		for(int j=0; j<2; j++){
			for(int i=1; i<=n; i++){
				if(j==0){
					scanf("%d", &candy[i]);
					if(min_c>candy[i]){
						min_c = candy[i];
					}
				}
				else{
					scanf("%d", &orange[i]);
					if(min_o>orange[i]){
						min_o = orange[i];
					}		
				}	
			}
		}

		for(int i=1; i<=n; i++){
			candy[i]-=min_c;
			orange[i]-=min_o;
		}
		for(int i=1; i<=n; i++){
			cnt+=max(orange[i],candy[i]);
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
