//AC
//BOJ 1065 한수
#include <stdio.h>
int main(){
	int arr[1000] = {0};
	int n, i, fir,sec,thi, count = 0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		arr[i] = i+1;
	}
	if(n<100) 	printf("%d", n);
	else{
		for(i = 99; i<n; i++){
			fir = arr[i] / 100;
			sec = (arr[i] % 100) / 10;
			thi = (arr[i]%100) % 10;
			if(thi-sec == sec - fir) 	count++;
		}
		printf("%d", count+99);
	}
	return 0;
}
