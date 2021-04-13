#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int arr[51];
int main(){
	int prev = 0, n, q, num = 0, cnt = 1;
	cin >> n >> q;
	for(int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		num = max(num, a);
		if(arr[a] == 0){
			arr[a] = i+1;
		}
	}

	while(q--){
		int query;
		scanf("%d", &query);
		printf("%d ", arr[query]);
		for(int i=1; i<=num; i++){
			if(arr[query] > arr[i]){
				arr[i] += 1;
			}
		}
		arr[query] = 1;
	}
	return 0;
}