#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
    queue<pair<int, int>> que; // (우선순위, 위치)
    priority_queue<int> pq;
        
    for(int i = 0; i < priorities.size(); i++)
    {
        que.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!que.empty()) {
        pair<int, int> target = que.front();
        que.pop();
        
        // 현재 있는 아이들 중 가장 큰 값인지? 
        if(target.first == pq.top()) {
            answer+=1;
            pq.pop();
            if(target.second == location) break;
        }
        else que.push(target);
    }
	return answer;
}