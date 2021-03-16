#include <iostream>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int b;
	for(int i=0; i<n; i++){
		scanf("%d", &b);
	}
	for(int i=2; i<=n/2; i++){
		if(n%i==0){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}
