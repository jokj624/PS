//AC
//BOJ 9498 시험 성적
#include <stdio.h>
int main(){
	int score;
	
	scanf("%d", &score);
	
	switch(score/10){
		case 10:
			printf("A");	break;
		case 9:	
			printf("A");	break;
		case 8:
			printf("B");	break;
		case 7:
			printf("C"); 	break;
		case 6: 
			printf("D");	break;
		default:
			printf("F");	
	}
	return 0;
}
