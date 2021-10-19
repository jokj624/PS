//AC
//BOJ 1026 보물
#include <stdio.h>
int bubble(int num[], int n);
int main(){
	int a[50], b[50], c[50];
	int n, i, s=0, j;
	scanf("%d",&n);
	for(i=0; i<n; i++)	scanf("%d", &a[i]);
	for(i=0;i<n;i++) 	scanf("%d", &b[i]);
	for(i=0;i<n; i++) 	c[i] = b[i];
	bubble(a, n);
	bubble(c, n);
	j=n;
	for(i=0;i<n;i++){
		s+= a[i] * c[--j];
	}
	printf("%d", s);
	return 0;
}
int bubble(int num[], int n){
	int i, j, temp;
	for(i=0; i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(num[j]>num[j+1]){
				temp = num[j];
				num[j]=num[j+1];
				num[j+1] = temp;
			}
		}
	}
}
