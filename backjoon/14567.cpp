#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> outdegree[1001];
int indegree[1001];

int main(){ 
  int n, m;
  
  scanf("%d %d", &n, &m);
  vector<int> lec (n+1, 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    outdegree[a].push_back(b);
    indegree[b]+=1;
  }

  queue<int> que;
  for(int i=1; i <= n; i++) {
    if(indegree[i] == 0) que.push(i);
  }

  vector<int> answer (n+1, 0);
  for(int i = 1; i <= n; i++) {
    if(que.empty()) break;
    int start = que.front();
    que.pop();
    answer[start] = lec[start];
    for(int a : outdegree[start]) {
      if(--indegree[a] == 0) {
        que.push(a);
        lec[a] = lec[start] + 1;
      }
    }
  }

  for(int i = 1; i <= n; i++)
    printf("%d ", answer[i]);
  return 0;
}
