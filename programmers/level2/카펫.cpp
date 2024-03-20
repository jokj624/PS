// AC
// programmers - level2 - 카펫
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int result1 = 0, result2 = 0;
    
    int sum = brown + yellow;
    
    for (int i = 3; i <= sum / 2; i++) {
        int col = sum / i;
        int yellow_col = col - 2;
        int yellow_row = i - 2;
        
        
        if ((yellow_col * yellow_row) == yellow) {
            result1 = min(i, col);
            result2 = max(i, col); 
            break;
        }
    }
    answer.push_back(result2);
    answer.push_back(result1);
    return answer;
}
