//코포 div2 A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		vector<int> v;
		int n, k, ans = -1, sum = 0;
		scanf("%d %d", &n, &k);
		if(n==1){
			if(k==0){
				printf("1\n");
			}
			else{
				printf("-1\n");
			}
		}else{
			if(k==0){
				for(int i=1; i<=n; i++){
					printf("%d ", i);
				}
				printf("\n");
			} else {
			
			int l = 2, r = n, idx = 0;
			v.push_back(1);
			while(n--){
				if(ans != -1){
					int cnt = n;
					while(cnt--){
						v.push_back(l);
						l += 1;
					}
					break;
				}
				if(!(n%2)){
					v.push_back(r);
					r-=1;
					idx += 1;
				}
				else{
					v.push_back(l);
					l+=1;
					idx += 1;
				}
				if(v.size() >= 3){
					if(v[idx-1] > v[idx-2] && v[idx-1] > v[idx]) {
						sum += 1;
					}
					if(sum == k){
						ans = sum;
					}
				}
			}
			if(sum != k){
				printf("-1\n");
			}
			else if(sum == k){
				for(int num : v){
					printf("%d ", num);
				}printf("\n");
			}
		}
		}
	}
}