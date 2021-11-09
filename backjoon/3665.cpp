#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int outdegree[501][501];  // [선][후]
int indegree[501];

int main(){
  int n;
  scanf("%d", &n);
  while(n--) {
    int team;
    int vec[501] = {0, };
    memset(outdegree, 0, sizeof(outdegree));
    memset(indegree, 0, sizeof(indegree));

    scanf("%d", &team);
    for(int i = 0; i < team; i++) {
      scanf("%d", &vec[i]);
    }
    for(int i = 0; i < team; i++) {
      for(int j = i+1; j < team; j++) {
        outdegree[vec[i]][vec[j]] = 1;
        indegree[vec[j]] += 1;
      }
    }
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
      int win, lose;
      scanf("%d %d", &win, &lose);
      if (outdegree[win][lose] == 1) {  // 방향을 바꿔야 하는 것이기 때문에, 기존 연결 관계도 제거 
        outdegree[win][lose] = 0;
        outdegree[lose][win] = 1;
        indegree[lose]-=1;
        indegree[win]+=1;
      }
      else {
        outdegree[lose][win] = 0;
        outdegree[win][lose] = 1;
        indegree[win]-=1;
        indegree[lose]+=1;
      }
    }
    // 위상 정렬
    queue<int> que;
    vector<int> answer;
    for (int i = 1; i <= team; i++)
    {
      if (indegree[i] == 0)
        que.push(i);
    }

    for (int i = 1; i <= team; i++)
    {
      if (que.empty())
      {
        printf("IMPOSSIBLE\n");
        break;
      }
      int start = que.front();
      que.pop();
      answer.push_back(start);
      indegree[start] -= 1; // que에 push하는 조건 중복방지
      for (int j = 1; j <= team; j++)
      {
        if (outdegree[start][j])
          indegree[j] -= 1;

        if (indegree[j] == 0)
          que.push(j);
      }
    }
    if (answer.size() == team)
    {
      for (int i = 0; i < team; i++)
      {
        printf("%d ", answer[i]);
      }
      printf("\n");
    }
  } 

  return 0;
}