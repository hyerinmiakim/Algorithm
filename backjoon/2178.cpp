#include <stdio.h>
#include <queue>
using namespace std;

char map[101][101];
int check[101][101];
int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;

void bfs(int i)
{
  queue<pair<int, int> > que;
  que.push(make_pair(i, i));
  check[i][i] = 1;
  while (!que.empty())
  {
    pair<int, int> start = que.front();
    que.pop();
    for (int k = 0; k < 4; k++)
    {
      int cx = start.first + way[k][0];
      int cy = start.second + way[k][1];
      if (cx >= 0 && cx < n && cy >= 0 && cy < m)
      {
        if (check[cx][cy] == 0 && map[cx][cy] == '1')
        {
          check[cx][cy] = check[start.first][start.second] + 1;
          que.push(make_pair(cx, cy));
        }
      }
    }
  }
}
int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", &map[i]);
  
  bfs(0);
  printf("%d", check[n - 1][m - 1]);
}