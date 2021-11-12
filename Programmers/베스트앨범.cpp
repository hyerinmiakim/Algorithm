#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#define psvi pair<string, vector<pair<int, int>>>
using namespace std;

map<string, vector<pair<int, int>>> music; // 장르 별 (노래, 인덱스) 

bool cmp(psvi& a, psvi& b) {
    int mx=0, mx2=0;
    for(int i = 0; i < a.second.size(); i++)
        mx += a.second[i].first;
    for(int i = 0; i < b.second.size(); i++)
        mx2 += b.second[i].first;
    
    return mx > mx2;
}

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first)    return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 기준1. 노래가 많이 재생된 순서, 
    // 기준2. 장르 내에서 많이 재생된 순서
    // 기준3. 장르 내에서 재생 횟수가 같다면, 고유번호가 낮은 노래 먼저
    for(int i = 0; i < genres.size(); i++) {
        music[genres[i]].push_back({plays[i], i});
    }
    
    vector<psvi> vec (music.begin(), music.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for(int i = 0; i < vec.size(); i++) {
        sort(vec[i].second.begin(), vec[i].second.end(), cmp2);
        
        if(vec[i].second.size() > 1) {
            answer.push_back(vec[i].second[0].second);
            answer.push_back(vec[i].second[1].second);
        }
        else
            answer.push_back(vec[i].second[0].second);
    }
    
    return answer;
}