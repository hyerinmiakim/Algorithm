#include <map>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
// 17:58
// 10:15
// 보석이 다 채워졌는지 확인하는 함수 
map<string, int> jewel;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    set<string> tmp(gems.begin(), gems.end());  // 중복없이 가져올 수 있다.
    int left = 0, right = 0;
    int len = gems.size();
    int dist = 0;
    
    // 모든 보석이 다 차는 순간 판단
    for(auto s : gems) {
        jewel[s]+=1;
        if(jewel.size() == tmp.size()) break;    // gems이 가지고 있는 중복없는 보석의 수
        right++;
    }
    
    answer[0] = left + 1; 
    answer[1] = right + 1;
    dist = right - left;
    
    // left 이동해가면서 보석을 하나씩 빼본다
    while(right < len) {
        string target = gems[left];
        jewel[target]-=1;
        // 0이 되면 보석이 하나 빠지기 때문에 뺀 보석을 찾을 때 까지 right를 늘려준다
        if(jewel[target] == 0) {
            right += 1;
            for(; right < len; right++) {
                jewel[gems[right]]+=1;
                if(target == gems[right]) break;
            } 
            if(right == len) break;
        }
        left++;
        
        if(dist > right - left) {
            answer[0] = left + 1; 
            answer[1] = right + 1;
            dist = right - left;
        }
    }
    return answer;
}