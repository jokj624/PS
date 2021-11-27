//AC
//BOJ 2959 거북이
#include <stdio.h>
int quick_sort(int num[], int left, int right);
int main(){
	int i, arr[4];
	for(i=0; i<4; i++){
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, 3);
	printf("%d", arr[0]*arr[2]);
	return 0;
}
int quick_sort(int num[], int left, int right){
	int pivot, i, j, temp;
	if(left < right){
		i=left;
		j=right + 1;
		pivot = num[left];
		do{
			do{i++;}while(num[i]<pivot);
			do{j--;}while(num[j]>pivot);
			if(i<j){
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}while(i<j);
		temp = num[left];
		num[left]=num[j];
		num[j] = temp;
		quick_sort(num,left,j-1);
		quick_sort(num, j+1, right);
	}
}
