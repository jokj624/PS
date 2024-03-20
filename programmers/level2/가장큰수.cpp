// AC
// programmers - level2 - 가장 큰 수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    
    for (auto a : numbers) {
        str.push_back(to_string(a));
    }
    
    sort(str.begin(), str.end(), compare);
    
    for (auto a : str) {
        answer += a;
    }
    
    if (answer[0] == '0') return "0";
    
    return answer;
}
