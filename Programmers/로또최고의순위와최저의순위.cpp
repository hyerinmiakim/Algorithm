#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zero = 0, win = 0;
    vector<int> answer;
    for(int lotto : lottos) {
        if(lotto == 0) zero += 1;
        else if (find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()) win+=1;
    }
    // 순위 정하기
    // 다 틀리면: win 하나, 다 맞으면 win + zero
    // 두 번호의 순위 리턴
    int _max = (6 - (zero + win)) + 1;
    int _min = (6 - win) + 1;
    if(_max >= 6)   _max = 6;
    if(_min >= 6)   _min = 6;
    answer.push_back(_max);
    answer.push_back(_min);
    return answer;
}