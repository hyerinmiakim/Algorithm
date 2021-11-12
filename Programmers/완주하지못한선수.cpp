#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int>  mp;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i = 0; i < participant.size(); i++) {
        mp[participant[i]]+=1;
    }
    
    for(string s : completion) {
        if(mp.find(s) != mp.end()) {
            mp[s]-=1;
        }
    }
    for(auto m : mp) {
        if(m.second > 0)    answer += m.first;
    }
    return answer;
}
