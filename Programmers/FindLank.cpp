#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer(query.size(), 0);
    map<string, vector<int> > mp;
    vector<vector<string> > str(4, vector<string>(2, "-"));
    string scr = "";

    for (int i = 0; i < info.size(); i++)
    {
        istringstream ss(info[i]);
        ss >> str[0][0] >> str[1][0] >> str[2][0] >> str[3][0] >> scr;

        /* 모든 문자열 조합에 대하여 scr 넣어주기 */
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int m = 0; m < 2; m++)
                        mp[str[0][i] + str[1][j] + str[2][k] + str[3][m]].push_back(stoi(scr));
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
        sort(it->second.begin(), it->second.end());

    for (int i = 0; i < query.size(); i++)
    {
        istringstream ss(query[i]);
        string token, st = "", score = "";
        int idx = 0;
        while (ss >> token)
        {
            if (token == "and")
                continue;

            if (idx < 4)
                st += token;
            else
                score = token;
            idx++;
        }
        auto itr = lower_bound(mp[st].begin(), mp[st].end(), stoi(score));
        answer[i] = mp[st].size() - (itr - mp[st].begin());
    }

    return answer;
}

int main()
{
    vector<string> info;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");

    vector<string> query;
    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");
    vector<int> ret = solution(info, query);

    for (int i = 0; i < ret.size(); i++)
        cout << ret[i];

    return 0;
}