//AC
//BOJ 4344 평균은 넘겠지 
#include <stdio.h>
#define MAX 1000
int main(){
	int n, i, ave;
	scanf("%d", &n);
	while(n--){
		int student = 0, sum=0, count = 0;
		int score[MAX]={0};
		scanf("%d", &student);
		for(i=0; i<student; i++){
			scanf("%d", &score[i]);
			sum+=score[i];
		}
		ave = sum / student;
		for(i=0; i<student; i++){
			if(ave < score[i]) 	count++;
		}
		printf("%.3f%%\n",(float)count*100/student);
	}
	return 0;
}