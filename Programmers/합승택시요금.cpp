#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

#define INF 987654321
using namespace std;

vector<pair<int,int> > vec[201];   // 연결되어 있는 정점 정보
int fee[201][3];   // 3개의 정점이 시작점이 되었을 때 계산할 수 있는 각 경우의 최소 비용

void dijkstra(int start, int turn) {
    fee[start][turn] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({start, 0});
    while(!pq.empty()) {
        int cur = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();
        
        if(fee[cur][turn] < dist) continue;
        
        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int nextDist = dist + vec[cur][i].second;
            
            if(nextDist < fee[next][turn]) {
                fee[next][turn] = nextDist;
                pq.push({next, -nextDist});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i = 0; i < fares.size(); i++) {
        vec[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        vec[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 2; j++)
            fee[i][j] = INF;
    
    dijkstra(s, 0);
    dijkstra(a, 1);
    dijkstra(b, 2);
    
    for(int i = 1; i <= n; i++) {
        if(fee[i][0] == INF || fee[i][1] == INF || fee[i][2] == INF) continue;
        answer = min(answer, fee[i][0] + fee[i][1] + fee[i][2]);
    }
    return answer;
}