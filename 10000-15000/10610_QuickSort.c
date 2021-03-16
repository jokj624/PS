//AC
//BOJ 10610_QuicSort 30
//https://www.acmicpc.net/problem/10610 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Swap(int arr[], int a, int b) // a,b 스왑 함수 
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
	int low = left + 1;
	int high = right;

	while (low <= high) // 교차되기 전까지 반복한다 
	{
		while (pivot >= arr[low] && low <= right) // 피벗보다 큰 값을 찾는 과정 
		{
			low++; // low를 오른쪽으로 이동 
		}
		while (pivot <= arr[high] && high >= (left + 1)) // 피벗보다 작은 값을 찾는 과정 
		{
			high--; // high를 왼쪽으로 이동
		}
		if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
		{
			Swap(arr, low, high); //low와 high를 스왑 
		}
	}
	Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환 
	return high;  // 옮겨진 피벗의 위치정보를 반환 

}


void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // 둘로 나누어서
		QuickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
		QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
	}
}

int ten_check(char num[],int len) {
	int i, flag=0;
	for (i = 0; i < len; i++) {
		if (num[i] == '0') {
			flag = 1;
			break;
		}
	}
	if (flag == 0)	return 0;
	else	return 1;
}
void three_check(char num[], int len) {
	int i, sum=0,j;
	char temp;
	int arr[100001];
	for (i = 0; i < len; i++) {
		sum += (num[i] - '0');
	}
	if ((sum % 3)) {
		printf("-1");
		return;
	}
	else {
		for (i = 0; i < len; i++) {
			arr[i] = num[i] - '0';
		}
		QuickSort(arr, 0, len-1);
		for(i=len-1; i>=0; i--){
			printf("%d", arr[i]);
		}
	}
}
int main() {
	char num[100001];
	gets(num);
	int len, i;
	len = strlen(num);
	if (ten_check(num, len)) {
		three_check(num, len);
	}
	else {
		printf("-1");
	}
}
