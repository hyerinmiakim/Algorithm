#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, k, num; // 건물의 갯수, 건설순서규칙
    int time[100001] = {0};
    int indegree[1001] = {0};
    int dp[1001] = {0};

    scanf("%d%d", &n, &k);
    vector<int> build[n+1];
    
    for(int i = 1; i <= n; i++) {
      scanf("%d", &time[i]);
      dp[i] = time[i];
    }

    for(int i = 1; i <= k; i++) {
      int pre, cur;
      scanf("%d %d", &pre, &cur);
      build[pre].push_back(cur);
      indegree[cur]+=1;
    }
    scanf("%d", &num);

    /* 0 Indegree check */
    queue<int> que;
    for(int i = 1; i <= n; i++)
      if(indegree[i] == 0) que.push(i);

    for(int i = 1; i <= n; i++) {
      if(que.empty()) {
        printf("0");
        return 0;
      }

      int st = que.front();
      que.pop();
      if (st == num) break;
      
      for(int &a : build[st]) {
        if(--indegree[a] == 0) que.push(a);
        if(dp[a] < dp[st] + time[a])
          dp[a] = dp[st] + time[a];
      }
    }
    printf("%d\n", dp[num]);
  }
  return 0;
}