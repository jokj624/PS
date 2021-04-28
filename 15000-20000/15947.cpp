//AC
//BOJ 15947 아기석환 뚜루루 뚜루
#include <iostream>
using namespace std;
int main(){
	int n;
	int mod, n2;
	cin >> n;
	n2 = n/14;
	mod = n%14;
	if(mod == 1 ||mod==13)	cout << "baby" << endl;
	else if(mod == 2 || mod == 14 || mod == 0)	cout << "sukhwan" << endl;
	else if(mod == 5)	cout << "very" << endl;
	else if(mod == 6)	cout << "cute" << endl;
	else if(mod == 9)	cout << "in" << endl;
	else if(mod == 10)	cout << "bed" << endl;
	else{
		if(mod == 3 || mod == 7 || mod == 11){
			if(n2<3){						
				cout << "tururu";
				for(int i=1; i<=n2; i++)	cout << "ru";
			}
			else{
				cout << "tu+ru*"<< (n2+2);
			}
		}
		else if(mod==4 || mod==8 || mod==12){
			if(n2 < 4){
				cout << "turu";
				for(int i=1; i<=n2; i++) 	cout << "ru";
			}
			else	cout << "tu+ru*" << (n2+1);
		}
	}
}