//AC
//BOJ 1786 찾기  
//https://www.acmicpc.net/problem/1786

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> idx;
int cnt=0;
vector<int> makeTable(string pattern){
	int j = 0;
	vector<int> table(pattern.size(), 0);
	for(int i=1; i<pattern.size(); i++){
		while(j>0 && pattern[i]!=pattern[j]){
			j = table[j-1];
		}
		if(pattern[i]==pattern[j]){
			table[i] = ++j;
		}
	}
	return table;
}
void KMP(string parent, string pattern){
	vector<int> table = makeTable(pattern);
	int j = 0;
	for(int i=0; i<parent.size(); i++){
		while(j>0 && parent[i]!=pattern[j]){
			j = table[j-1];
		}
		if(parent[i]==pattern[j]){
			if(j == pattern.size()-1){
				cnt++;
				idx.push_back(i-pattern.size()+2);
				j = table[j];
			}
			else{
				j++;
			}
		}
	}
	return;
}
int main(){
	string pattern, parent;
	getline(cin, parent);
	getline(cin, pattern);
	KMP(parent, pattern);
	cout << cnt << "\n";
	for(int i=0; i<idx.size(); i++){
		printf("%d ", idx[i]);
	}
	return 0;
} 
