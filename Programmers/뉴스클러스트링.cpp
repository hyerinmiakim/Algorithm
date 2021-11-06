#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> s1;
vector<string> s2;

void parsingStr(string s, string ss) {
    
    transform (s.begin(), s.end(), s.begin(), ::toupper);
    transform (ss.begin(), ss.end(), ss.begin(), ::toupper);
    for(int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]) && isalpha(s[i+1])) {
            string tmp = s.substr(i, 2);
            s1.push_back(tmp);
        }
    }
    
    for(int i = 0; i < ss.size(); i++)
    {
        if(isalpha(ss[i]) && isalpha(ss[i+1])) {
            string tmp = ss.substr(i, 2);
            s2.push_back(tmp);
        }
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    int summ = 0;
    int exclu = 0;
    
    parsingStr(str1, str2);
    
    for(int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
            if(s1[i] == s2[j]) {
                exclu+=1;
                s2[j] = '#';
                break;
            }
        }
    }
    summ = s1.size() + s2.size() - exclu;
    if (summ == 0)  answer = 65536;
    else answer = (exclu * 65536) / summ;
    
    return answer;
}