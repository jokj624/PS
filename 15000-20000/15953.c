//AC
//BOJ 15953 상금 헌터 
//https://www.acmicpc.net/problem/15953 
#include <stdio.h>
int fir(int one);
int sec(int two);
int main(){
	int t, i, one,two;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d %d", &one, &two);
		printf("%d\n", fir(one)+sec(two));
	}
}
int fir(int one){
	int money;
	if(one == 0)	return 0;
	else if(one >= 22)	return 0;
	else{
		switch(one){
			case 1:	money=5000000;	break;
			case 2:
			case 3:	money=3000000;	break;
			case 4:	case 5:	case 6:	money=2000000;	break;
			case 7: case 8: case 9: case 10:	money=500000;	break;
			case 11:  case 12: case 13: case 14: case 15: 	money=300000;	break;
			default:	money = 100000;
		}
		return money;
	}
}
int sec(int two){
	int money;
	if(two >= 16 && two <= 31){
		money = 320000;
		return money;
	}
	else if(two == 0)	return 0;
	else if(two >= 32)	return 0;
	else{	
		switch(two){
			case 1: money = 5120000; 	break;
			case 2:	case 3:	money = 2560000;	break;
			case 4: case 5: case 6: case 7:	money=1280000; 	break;
			default: 	money = 640000; 	break;
		}
		return money;	
	}
}
