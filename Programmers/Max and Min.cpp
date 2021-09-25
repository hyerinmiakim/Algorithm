#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
int func(string a, string b) {
        if(stoi(a) < 0 || stoi(b) < 0)
        	return (stoi(a) < stoi(b) ? stoi(b) : stoi(a));
    }

string solution(string s) {
    string answer = ""; 
    vector<int> str;
    
    string tmp;
    istringstream iss(s);
    while(iss >> tmp)
        str.push_back(stoi(tmp));

    sort(str.begin(), str.end(), less<int>());
    answer = to_string(str.front()) + " " + to_string(str.back());
    
    //answer = *min_element(str.begin(), str.end()) + " " + *max_element(str.begin(), str.end());
    return answer;
}