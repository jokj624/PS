//AC
//BOJ 2467 용액
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9876543210
using namespace std;
typedef long long ll;
int arr[101010];
int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	int l = 0, r = N-1, ansL=0, ansR=1;
	ll ans = INF;
	while(l < r){
		if(l == r)	l++;
		ll sum;
		sum = arr[l]+arr[r];
		if(sum == 0){
			ansL = l;	ansR = r;
			break;
		}
		if(ans > abs(sum)){
			ans = abs(sum);
			ansL = l;
			ansR = r;
		}
		else if(sum < 0){
			l++;
		}
		else{
			r--; 
		}
	}
	if(ansL < ansR)		cout << arr[ansL] << " " << arr[ansR];
	else	cout << arr[ansR] << " " << arr[ansL];
	return 0;
}
