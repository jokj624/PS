//AC
//BOJ 5585 거스름돈
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int money, count = 0;
	cin >> money;
	money = 1000-money;
	while(money > 0){
		if(money >= 500){
			count += (money / 500);
			money %= 500;
		}
		else if(money >= 100){
			count += (money / 100);
			money %= 100;
		}
		else if(money >= 50){
			count += (money / 50);
			money %= 50;
		}
		else if(money >= 10){
			count += (money / 10);
			money %= 10;
		}
		else if(money >= 5){
			count += (money / 5);
			money %= 5;
		}
		else if(money >= 1){
			count += (money / 1);
			money %= 1;
		}
	}
	cout << count;
	return 0;
}
