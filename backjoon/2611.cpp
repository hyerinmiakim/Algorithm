#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int outdegree[1002][1002];
int indegree[1002];
int dp[1002]; // 가장 큰 점수
int visit[1002];
int n, m;
void func(int i) {
  if(i == 0)  return;
  func(visit[i]);
  if(i == n+1)  i = 1;
  printf("%d ", i);
}
int main(){ 
  
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int p, q, r;
    scanf("%d %d %d", &p, &q, &r);
    if(q == 1)  q = n+1;
    outdegree[p][q] = r;
    indegree[q]+=1;
  }

  queue<int> que;
  que.push(1);

  vector<int> answer (n+2, 0);

  for(int i = 1; i <= n+1; i++) {
    if(que.empty()) break;
    int start = que.front();
    que.pop();
    for(int j = 1; j <= n+1; j++) {
      if(outdegree[start][j]) {
        if(dp[j] < dp[start] + outdegree[start][j]) {
          dp[j] = dp[start] + outdegree[start][j];
          visit[j] = start;
        }
        if(--indegree[j] == 0)  que.push(j);
      }
    }
  }
  printf("%d\n", dp[n+1]);
  // 출력 재구성
  func(n+1);
  
  return 0;
}
