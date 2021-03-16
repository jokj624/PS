//AC
//BOJ 16360 Go Latin
//https://www.acmicpc.net/problem/16360
#include <stdio.h>
#include <string.h>
void go_latin(char str[]){
	char ch;
	ch = str[strlen(str)-1];
	switch(ch){
		case 'a':
			strcat(str, "s");
			break;
		case 'y':
			str[strlen(str)-1] = 'i';
		case 'i':
			strcat(str, "os");
			break;
		case 'n':
			str[strlen(str)-1] = 'a';
			strcat(str, "nes");	
			break;
		case 'e':
			if(str[strlen(str)-2] == 'n'){
				str[strlen(str)-2] = 'a';
				str[strlen(str)-1] = 'n';
				strcat(str, "es");	
			}
			else{
				strcat(str, "us");
			}
			break;
		case 'u':
		case 'o':
			strcat(str, "s");
			break;
		case 'v':
		case 'l':
		case 'r':
			strcat(str, "es");
			break;
		case 'w':
		case 't':
			strcat(str,"as");
			break;
		default :
			strcat(str, "us");
	}
	printf("%s\n", str);
}
int main(){
	int t;
	char ch;
	char str[22];
	scanf("%d", &t);
	while(t--){
		scanf("%s", str);
		go_latin(str);
		str[0] = '\0';
	}
	return 0;
}
