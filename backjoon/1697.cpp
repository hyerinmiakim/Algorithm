#include <stdio.h>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 100001
// 14:04
int n, k;
bool check[MAX+1];

int bfs(int target, int depth)
{
  int time = 0;
  queue<pair<int, int>> que;
  que.push({target, depth});

  while (!que.empty())
  {
    int x = que.front().first;
    int dep = que.front().second;
    check[x] = true;
    que.pop();
    if (x == k)
    {
      return dep;
    }

    int ax = x * 2;
    int bx = x + 1;
    int cx = x - 1;
    if (ax >= 0 && ax < MAX && check[ax] == false)
      que.push({ax, dep + 1});
    if (bx >= 0 && bx < MAX && check[bx] == false)
      que.push({bx, dep + 1});
    if (cx >= 0 && cx < MAX && check[cx] == false)
      que.push({cx, dep + 1});
  }

  return 0;
}

/* dfs를 하면 안되는 이유: k를 찾기 전 까지 명확한 재귀 중단 조건이 없음.
void dfs(int target) {
  if(check[target]) return;
  check[target] = true;
  dfs(target * 2);
  dfs(target + 1);
  dfs(target - 1);
}*/
int main()
{
  scanf("%d%d", &n, &k);
  printf("%d\n", bfs(n, 0));
  return 0;
}
