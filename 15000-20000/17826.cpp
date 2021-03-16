//AC
//BOJ 17826 나의 학점은?
//https://www.acmicpc.net/problem/17826
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int cnt=0;
	
	for(int i=0; i<50; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	int hong;
	cin >> hong;
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<50; i++){
		cnt++;
		if(v[i]==hong){
			break;
		}
	}
	if(cnt >=1 && cnt <=5)	cout << "A+";
	else if(cnt>=6 && cnt<=15)	cout << "A0";
	else if(cnt>=16 && cnt<=30)	cout << "B+";
	else if(cnt>=31 && cnt<=35)	cout<<"B0";
	else if(cnt>=36&&cnt<=45)	cout <<"C+";
	else if(cnt>=46 && cnt<=48)	cout <<"C0";
	else 	cout << "F";
	return 0;
}
