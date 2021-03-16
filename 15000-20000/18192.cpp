//AC
//BOJ 18192 보고 정렬
#include "bogoSort.h"
#include <algorithm>
#include <vector>
void sort_array(int N)
{
	int s = 0, e = N-1, flag = 0;
	std:: vector<int> temp;
	std:: vector<int> arr = copy_array();
	temp = arr;
	std:: sort(temp.begin(), temp.end());
	while(1){
		flag = 0;
		for(int i=0; i<arr.size(); i++){
			if(arr[i] != temp[i]){
				flag = 1;
				break;	
			}
		}
		if(!flag)	break;
		while(s != arr[s]){
			for(int i = s; i<N; i++){
				if(arr[i] == s){
					e = i;
					break;
				}
			}
			shuffle_array(s, e);
			arr = copy_array();
		}
		s += 1;
	}
}
