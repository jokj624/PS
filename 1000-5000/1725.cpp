//BOJ 1726 히스토그램
#include <iostream>
#define MAX 101010
using namespace std;
long long int arr[MAX];
int N;
long long int long_max(long long int a, long long int b){
	if(a>b) 	return a;
	else 	return b;
}
long long int long_min(long long int a, long long int b){
	if(a>b) 	return b;
	else 	return a;
}

long long int histogram(int l, int r){
	if(l == r){
		return arr[l];
	}
	int mid = (l+r)/2;
	long long int leftAns = 0, rightAns = 0;
	leftAns = histogram(l, mid);
	rightAns = histogram(mid+1, r);
	long long int minH = long_min(arr[mid], arr[mid+1]);
	long long int base = 2, midAns = minH * base;
	int idx1 = mid, idx2 = mid+1;
	while(l<idx1 && idx2 < r){
		if(arr[idx1-1] < arr[idx2+1]){	
			minH = long_min(minH, arr[idx2+1]);
			idx2+=1; 	base+=1;            
		}
		else{	
			minH = long_min(minH, arr[idx1-1]);
			idx1-=1; 	base+=1;            
		}
		midAns = long_max(midAns, base*minH);
	}
	while(l < idx1){
		idx1-=1;
		minH = long_min(minH, arr[idx1]);
		base+=1;
		midAns = long_max(midAns, base*minH);
	}
	while(r > idx2){
		idx2+=1;
		minH = long_min(minH, arr[idx2]);
		base+=1;
		midAns = long_max(midAns, base*minH);
	}
	return long_max(leftAns, long_max(midAns, rightAns)); 
}
int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%lld", &arr[i]);
	}
	printf("%lld", histogram(0, N-1));
	return 0;
}
