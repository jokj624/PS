//AC
//BOJ 5430 AC 
//https://www.acmicpc.net/problem/5430
#include <iostream> 
#include <deque> 
#include <string> 

using namespace std; 

int main() { 
	bool chk; 	// true이면 앞에서 false이면 뒤에서 
   	bool ok; 		// 비어있을 때 D 호출하면 error
    int T, n;  
  	cin >> T; 
	while (T--){ 
		string cmd = "";
 		string input_arr = "";
	    deque<int> dq; 
		ok = true; 
		chk = true; 

		cin >> cmd;		// 수행할 함수
		cin >> n;			// 배열에 들어있는 수의 개수
		cin >> input_arr;		// 배열을 담을 문자
		string num = "";	 	// dq에 넣을 수
		for (int i = 0; i < input_arr.length(); ++i) {  // deque로 만들기 
        	if (input_arr[i] == ',' || input_arr[i] == ']') { 
		    	if (input_arr[i - 1] == '[') 		break; 
	        	dq.push_back(atoi(num.c_str())); 
		    	num = ""; 
				} 
            	else if (input_arr[i] != '[' && input_arr[i] != ']')  num += input_arr[i]; 
    	}
    	for(int i =0; i<cmd.size(); i++){
    		if(cmd[i] == 'R'){
    			if(chk)	chk = false;
    			else 	chk = true;
			}
			else if(cmd[i]=='D'){
				if(dq.size()<=0)	{
					ok = false;
					break;
				}
				else{
					if(chk)	dq.pop_front();
					else 	dq.pop_back();
				}
			}
		}
		if(!ok)	cout << "error" << endl;
		else{
			cout << "[";
			for(i=0; i<dq.size(); i++){
				if(chk){
					cout << dq.front();
					dq.pop_front();
					if(!dq.empty())	cout << ", ";
				}
				else{
					cout << dq.back();
					dq.pop_back();
					if(!dq.empty())	cout << ", ";
				}
			}	
		}
		cout << "]" << endl;
	}
}
