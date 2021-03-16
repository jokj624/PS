//AC
//BOJ 2896 무알콜 칵테일
//https://www.acmicpc.net/problem/2896 
#include <stdio.h>
int main(){
	float orange, apple, pine;
	float i,j,k;
	float mi, mj, mk, min;
	scanf("%f %f %f", &orange, &apple, &pine);
	scanf("%f %f %f", &i, &j, &k);
	mi = orange /i;
	mj = apple / j;
	mk = pine / k;
	
	min = (mi > mj ? (mj < mk ? mj : mk) : (mi < mk) ? mi : mk);
	
	orange -= (min*i);
	apple -= (min * j);
	pine -= (min * k);
	
	printf("%.6f %.6f %.6f", orange, apple, pine);
	return 0;
}
	

