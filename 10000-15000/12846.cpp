
//BOJ 12846 무서운 아르바이트 
#include <iostream>
using namespace std;
int money[101010];
long long int l_max(long long int a, long long int b){
	if(a>b)	return a;
	else 	return b;
}
long long int l_min(long long int a, long long int b){
	if(a>b)	return b;
	else 	return a;
}
long long int maxMoney(int l, int r){
	if(l==r) 	return (long long int) money[l];
	int mid = (l+r)/2;
	long long int leftMoney = maxMoney(l, mid);
	long long int rightMoney = maxMoney(mid+1, r);
	int idx1 = mid, idx2 = mid+1;
	long long int minMoney = l_min(money[idx1], money[idx2]);
	long long int day = 2;
	long long int midMoney = day*minMoney;
	
	while(l < idx1 && r > idx2){
		if(money[idx1-1] < money[idx2+1]){
			minMoney = l_min(minMoney, money[idx2+1]);
			idx2++; 	day++;
		}
		else{
			minMoney = l_min(minMoney, money[idx1-1]);
			idx1--;  	day++;
		}
		midMoney = l_max(midMoney, minMoney * day);
	}
	while(l < idx1){
		minMoney = l_min(money[idx1-1], minMoney);
		idx1--; day++;
		midMoney = l_max(midMoney, minMoney * day);
	}
	while(r > idx2){
		minMoney = l_min(money[idx2+1], minMoney);
		idx2++; day++;
		midMoney = l_max(midMoney, minMoney * day);
	}
	return l_max(leftMoney, l_max(midMoney, rightMoney));
}
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &money[i]);		
	}
	printf("%lld", maxMoney(0, n-1));
	return 0;
}