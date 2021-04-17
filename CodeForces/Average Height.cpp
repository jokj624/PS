#include <iostream>
#include <vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, h;
		vector<int> odd;
		vector<int> even;
		cin >> n;
		for(int i=0; i<n; i++){
			scanf("%d", &h);
			if(h % 2 == 1){
				odd.push_back(h);
			}
			else if(h%2 == 0){
				even.push_back(h);
			}
		}
		for(int ans : odd){
			printf("%d ", ans);
		}
		for(int ans : even){
			printf("%d ", ans);
		}
		printf("\n");
	}
	return 0;
}