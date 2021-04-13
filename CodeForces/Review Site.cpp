#include <iostream>
#include <vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int ans = 0;
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int num;
			scanf("%d", &num);
			if(num == 1 || num == 3){
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}