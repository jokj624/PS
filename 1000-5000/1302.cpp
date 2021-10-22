//AC
//BOJ 1302 베스트셀러
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
struct book{
	string name;
	int sell;
};
bool cmp(book a, book b){
	if(a.sell == b.sell){
		return a.name<b.name;
	}
	else	return a.sell > b.sell;
}
int main(){
	int n;
	scanf("%d", &n);
	book *read = new book[n];
	for(int i=0; i<n; i++){
		cin >> read[i].name;
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			//if(i==j)	continue;
			if(read[i].name == read[j].name){
				read[j].sell++;
			}
		}
	}
	sort(read, read+n, cmp);
	cout << read[0].name;
	return 0;
}
