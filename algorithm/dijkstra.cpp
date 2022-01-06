#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000
int number = 6; // 정점 수
vector<pair<int, int> > arr[7]; // 간선 정보. {연결된 정점, 비용}
int d[7]; // 최소 비용

void dijkstra(int start) {
  d[start] = 0;
  priority_queue<int, pair<int, int> > pq;
  pq.push(make_pair(start, 0));

  while(!pq.empty()) {
    int cur = pq.top().first; // 현재 노드
    int dist = -pq.top().second;  // 짧은 것이 먼저 오도록 음수화 한다. 
    pq.pop();

    if(d[cur] < dist) continue; // 최단 거리가 아닌 경우 스킵
    
    // 현재 노드의 인접 노드 중 최단으로 갈 수 있는 노드가 있는지 확인
    for(int i = 0; i < arr[cur].size(); i++) {
      int next = arr[cur][i].first;
      int nextDist = dist + arr[cur][i].second; // 선택된 노드를 인접 노드를 거쳐서 가는 비용
      // 더 짧은 경우 업데이트
      if(nextDist < d[next]) {
        d[next] = nextDist;
        pq.push(make_pair(next, -nextDist));
      }
    }
  }

}
int main(){
  for(int i=1; i<=number; i++) {
    d[i] = INF;
  }

  arr[1].push_back(make_pair(2,2));  
  arr[1].push_back(make_pair(3,5));
  arr[1].push_back(make_pair(4,1));  
  
  arr[2].push_back(make_pair(1,2));  
  arr[2].push_back(make_pair(3,3));
  arr[2].push_back(make_pair(4,2));  

  arr[3].push_back(make_pair(1,5));  
  arr[3].push_back(make_pair(2,3));
  arr[3].push_back(make_pair(4,3));  
  arr[3].push_back(make_pair(5,1));  
  arr[3].push_back(make_pair(6,5));

  arr[4].push_back(make_pair(1,1));  
  arr[4].push_back(make_pair(2,2));  
  arr[4].push_back(make_pair(3,3));  
  arr[4].push_back(make_pair(5,1));

  arr[5].push_back(make_pair(3,1));  
  arr[5].push_back(make_pair(4,1));
  arr[5].push_back(make_pair(6,2)); 

  arr[6].push_back(make_pair(3,5));  
  arr[6].push_back(make_pair(5,2));

  dijkstra(1);

  for(int i = 1; i <= number; i++)
    printf("%d ", d[i]);
  return 0;
}
