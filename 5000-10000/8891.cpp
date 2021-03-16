//AC
//BOJ 8891 점 숫자 
// https://www.acmicpc.net/problem/8891
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
int xarr[2];
void search(int a){
	int x, y, temp;
	for(int i=1; i<=a; i++){
		if(arr[i]==a){
			temp = i;
			break;
		}
		else if(arr[i] > a){
			temp = i-1;
			break;
		}
	}
	int d=a-arr[temp];
	if(d==0){
		xarr[0] = 1;
		xarr[1] = temp;
	}
	else{
		xarr[0] = 1;
		xarr[1] = temp;
		while(d>0){
			xarr[0] += 1;
			xarr[1] -= 1;
			d--;
		}
	}
}
int change(int x, int y,int a){
	int temp;
	int xx,yy;
	for(int i=1; i<=a; i++){
		if(arr[i] == a){
			temp = i+1;
			break;
		}
		else if(arr[i] > a){
			temp = i;
			break;
		}
		temp=i;
	}
	for(int i=temp; i<=10000; i++){
		xx=1;
		yy=i;
		for(int j=2; j<=i; j++){
			xx += 1;
			yy -= 1;
			if(xx == x && yy == y){
				return (arr[i]+j-1);
			}
		}
	}
}
int main(){
	int t;
	int temp=1;
	arr[1] = 1;
	for(int i=2; i<=10000; i++){
		arr[i] = arr[i-1]+temp;
		temp++;
	}
	scanf("%d", &t);
	while(t--){
		int a,b,x1,x2,y1,y2;
		int p,q;
		scanf("%d %d", &a,&b);
		search(a);
		x1 = xarr[0];
		y1 = xarr[1];
		search(b);
		x2 = xarr[0];
		y2 = xarr[1];
		p = x1+x2;
		q = y1+y2;
		printf("%d\n", change(p,q, max(a,b)));
	}
	return 0;
}
