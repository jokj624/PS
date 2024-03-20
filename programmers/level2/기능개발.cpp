// AC
// programmers - level2 - 기능개발
#include <string>
#include <vector>
using namespace std;

int divideAndCeil(int a, int b) {
    return (a + b - 1) / b;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    
    int size = progresses.size();
    
    int firstTask = divideAndCeil((100 - progresses[0]), speeds[0]);    
    day.push_back(firstTask);
    
    int deployCnt = 1;
    
    for (int i = 1; i < size; i++) {
        int remain = 100 - progresses[i];
        int taskDay = divideAndCeil(remain, speeds[i]);
        
        if (taskDay <= day.back()) {
            deployCnt++;
        } else {
            day.push_back(taskDay);
            answer.push_back(deployCnt);
            deployCnt = 1;
        }
    }
    
    answer.push_back(deployCnt);
    
    return answer;
}
