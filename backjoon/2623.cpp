#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main() {

  int n, m; //가수, 피디
  int indegree[1001] = {0};
  vector<int> sing[1001];

  scanf("%d%d", &n , &m);

  for(int i = 0;i<m; i++) {
    int T, pre, cur;
    scanf("%d", &T);
    scanf("%d", &pre);
    for(int j = 1; j < T; j++) {
      scanf("%d", &cur);
      indegree[cur]++;  //pre -> cur의 형태이니, cur의 Indegree 증가
      sing[pre].push_back(cur);
      pre = cur;
    }

  }

  int res[1001];
  queue<int> que;

  for(int i = 1; i <= n; i++) {
    if(indegree[i] == 0)  que.push(i);
  }

  for(int i = 1; i <= n; i++) {
    if(que.empty()) {
      printf("0");
      return 0;
    }

    int pos = que.front();
    que.pop();
    res[i] = pos;
    for(int a : sing[pos]) {  //pos의 Outdegree 정점들의 indegree를 감소해줌
      if(--indegree[a] == 0)  que.push(a);
    }
  }

  for(int i = 1; i <= n; i++)
    printf("%d\n", res[i]);
  return 0;

}