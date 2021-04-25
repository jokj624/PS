#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long a;
		long long num;
		int cnt = 0;
		cin >> num;
		if(num < 2050){
			printf("-1\n");
		} 
		else {
			string s = to_string(num);
			a = 2050 * pow(10, s.size()-3);
			while(num > 0){
				while(num < a){
					a /= 10;
					if(a < 2050){
						num = -1;
						break;
					}
				}
				if(num == -1)	break;
				if(num / a != 0){
					cnt += (num / a);
					num %= a;
				}
				else  	break;
			}
			if(num == 0)	printf("%d\n", cnt);
			else	printf("-1\n");
		}
	}
	return 0;
}