//AC
//BOJ 2775 부녀회장이 될테야 
// https://www.acmicpc.net/problem/2775
void resi(int a, int b){
	int arr[15][15] = {0};
	int i,j,k;
	for(int i=1; i<=b; i++){
		arr[0][i] = i;
	}
	for(i=1; i<=a; i++){
		for(j=1; j<=b; j++){
			for(k=1; k<=j; k++){
				arr[i][j] += arr[i-1][k];
			}	
		}
	}	
	printf("%d\n", arr[a][b]);
	return;
}
int main(){
	int t, a,b;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		resi(a,b);
	}
}
