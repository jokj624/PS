//AC
//BOJ 1969 DNA
//https://www.acmicpc.net/problem/1969
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, m, temp;
	char str[1001][51];
	char ans[51];
	int num=0, idx;
	int cnt[4] = {0};
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(str[j][i] == 'A')	cnt[0]++;
			else if(str[j][i] == 'C')	cnt[1]++;
			else if(str[j][i] == 'G')	cnt[2]++;
			else if(str[j][i] == 'T')	cnt[3]++;
		}
		temp = max(cnt[3],max(cnt[2],max(cnt[0],cnt[1])));
		if(temp == cnt[0])	{
			ans[i] = 'A';	
			idx = 0;
		}
		else if(temp == cnt[1])	{
			ans[i] = 'C';	
			idx = 1;
		}
		else if(temp == cnt[2])	{
			ans[i] = 'G';
			idx = 2;
		}
		else if(temp == cnt[3])	{
			ans[i] = 'T';
			idx = 3;
		}
		for(int p=0; p<4; p++){
			if(p==idx)	continue;
			num+=cnt[p];
		}
		cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	}
	printf("%s\n%d", ans, num);
	return 0;
}
