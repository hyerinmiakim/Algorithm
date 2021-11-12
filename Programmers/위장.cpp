#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;    // 종류, 종류 갯수
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i = 0; i < clothes.size(); i++) {
        if(mp.find(clothes[i][1]) != mp.end())
            mp[clothes[i][1]] += 1;
        else
            mp[clothes[i][1]] = 1;
    }
    
    // 경우의 수 : 해당 옷을 입는 경우의 수 + 안입는 경우의 수
    for(auto a : mp) {
        answer *= (a.second + 1);
    }
    // 문제 조건 : 하루에 최소 한 개의 의상은 입는다. 그래서 -1.
    return answer - 1;
}
