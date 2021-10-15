#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

vector<int> vec[20001];
bool check[20001];

bool cmp(int a, int b) {
     return a > b;
}
   
int bfs(int start) {
    queue<int> que;
    vector<int> depth (20001, 0);
    
    que.push(start);
    check[start] = true;
    depth[start] = 0;	// count[정점] = 깊이
	int cnt = 0;
    while(!que.empty()) {
        int point = que.front();
        que.pop();
        
        for(int i = 0; i < vec[point].size(); i++) {
            if(check[vec[point][i]] == false)	// 연결되어잇는 애들 중에,,, 방문하지 않았따.?
            {
                que.push(vec[point][i]);
                depth[vec[point][i]] = depth[point] + 1;
                check[vec[point][i]] = true;
            }
        }
    }
    sort(depth.begin(), depth.end(), cmp);
    for(auto a : depth) {
        if(depth[0] == a)
            cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++) {
        vec[edge[i][0]].push_back(edge[i][1]);
        vec[edge[i][1]].push_back(edge[i][0]);
    }
        
    answer = bfs(1);
    return answer;
}