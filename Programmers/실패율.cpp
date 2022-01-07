#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

bool cmp (pair<double, int> a, pair<double, int> b) {
    if(a.first == b.first) return a.second < b.second; 
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int len = stages.size();
    vector<pair<double, int> > vec; //{실패율, 스테이지 번호}
    
    for(int i = 1; i <= N; i++) {
        int noClear = 0;
        int clear = 0;
        for(int j = 0; j < len; j++) {
            if (stages[j] >= i) clear += 1;
            if (stages[j] == i) noClear += 1;
        }
       
        if(clear == 0) vec.push_back({0, i});
        else {
            double score = (double)noClear / (double)clear;
            vec.push_back({score, i});
        }

    }
  
    sort(vec.begin(), vec.end(), cmp);
    for(auto a : vec)
        answer.push_back(a.second);
    return answer;
}