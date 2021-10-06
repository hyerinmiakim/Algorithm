#include <stdio.h>
#include <queue>
using namespace std;
int n, m, k, a, b;
bool check[102][102];
int ground[102][102];
int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int bfs(int x, int y)
{
  queue<pair<int, int> > que;
  que.push(make_pair(x, y));
  int cnt = 1;
  while (!que.empty())
  {
    pair<int, int> start = que.front();
    que.pop();
    for (int p = 0; p < 4; p++)
    {
      int cx = start.first + way[p][0];
      int cy = start.second + way[p][1];
      if (cx >= 1 && cx <= n && cy >= 1 && cy <= m)
      {
        if (check[cx][cy] == false && ground[cx][cy] == 1)
        {
          check[cx][cy] = true;
          que.push(make_pair(cx, cy));
          ++cnt;
        }
      }
    }
  }
  return cnt;
}
int main() {
  scanf("%d %d %d", &n, &m,&k);
  for(int i = 0; i < k; i++) {
    scanf("%d %d", &a, &b);
    ground[a][b] = 1;
  }
  int max = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(check[i][j] == false && ground[i][j] == 1) {
        check[i][j] = true;
        int cnt = bfs(i, j);
        if(max < cnt)
          max = cnt;
      }
    }
  }
  printf("%d", max);
  return 0;
}