#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int lastDay = 0;
    for(int i = 0; i < progresses.size(); i++) {
        int work = 100 - progresses[i];
        int days;
        if(work % speeds[i])
        {
            days = work/speeds[i] + 1;
        }
        else days = work/speeds[i];
        
        if(lastDay < days)
        {
            answer.push_back(1);
            lastDay = days;
        }
        else {
            int tmp = answer.back() + 1;
            answer.pop_back();
            answer.push_back(tmp);
        }
    }
    return answer;
}