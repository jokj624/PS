#include <iostream>
#include <deque>
using namespace std;
int num[500001] = {0};
deque<int> dq;
int main(){
	int n, k, idx;
	scanf("%d %d", &n, &k);
	idx = n-k;
	for(int i=0; i<n; i++){
		scanf("%1d", &num[i]);
	}
	for(int i=0; i<n; i++){
		if(dq.empty()){
			dq.push_back(num[i]);
		}
		else{
			while(k&&dq.back()<num[i]){
				dq.pop_back();
				k--;
				if(dq.empty())	break;
			}
			dq.push_back(num[i]);
		}
		if(k==0)	break;
	}
	// if(dq.size()==n){
	// 	for(int i=0; i<idx; i++){
	// 		printf("%d", num[i]);
	// 	}
	// 	return 0;
	// }
	// idx-=dq.size();
	// while(!dq.empty()){
	// 	deque<int>::iterator temp = dq.begin();
	// 	printf("%d",*temp);
	// 	dq.pop_front();
	// }
	// if(idx!=0){
	// 	for(int i=n-idx; i<n; i++){
	// 		printf("%d", num[i]);
	// 	}
	// }
	for(int i=0; i<dq.size()-k; i++){
		printf("%d", dq[i]);
	}
	return 0;
}