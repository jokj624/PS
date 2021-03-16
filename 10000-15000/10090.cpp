//AC
//BOJ 10090 counting inversions
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
long long cnt = 0;
void merge(int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1], R[n2+1];
	for(int i=0; i<n1; i++){
		L[i] = v[i+p];
	}
	for(int i=0; i<n2; i++){
		R[i] = v[i+1+q];
	}
	L[n1] = 2147483646; 	R[n2] = 2147483646;
	int x = 0, y = 0;
	while(x < n1 || y < n2){
		if(L[x] <= R[y]){
			v[p+x+y] = L[x];
			x+=1;
		}
		else{
			v[p+x+y] = R[y];
			cnt += (n1-x);
			y+=1;
		}
	}
}
void mergeSort(int p, int r){
	int q = 0;
	if(p<r){
		q = (int)((p+r)/2);
		mergeSort(p,q);
		mergeSort(q+1, r);
		merge(p,q,r);
	}
}
int main(){
	int n, a;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		v.push_back(a);
	}
	mergeSort(0, n-1);
	cout << cnt;
	return 0;
}