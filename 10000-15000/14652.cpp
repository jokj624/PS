//AC
//BOJ 14652 나는 행복합니다~
#include <iostream>
using namespace std;
int main(){
	int n,m,num,cur=0;
	cin >> n >> m >> num;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(cur < num){
            	cur++;
                continue;
            }
		    if(cur == num){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
