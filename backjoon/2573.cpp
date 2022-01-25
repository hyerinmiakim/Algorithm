#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int board[301][301];
bool check[301][301];
int n, m;
int pos[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void bfs(int x, int y)
{
  queue<pair<int, int> > que;
  que.push({x, y});
  check[x][y] = true;

  while (!que.empty())
  {
    int ax = que.front().first;
    int ay = que.front().second;
    que.pop();

    for (int i = 0; i < 4; i++)
    {
      int cx = ax + pos[i][0];
      int cy = ay + pos[i][1];
      if (cx < 0 || cy < 0 || cx >= n || cy >= m)
        continue;
      if (check[cx][cy])
        continue;
      if (board[cx][cy] == 0)
        board[ax][ay] = max(0, board[ax][ay] - 1);
      else
      {
        check[cx][cy] = true;
        que.push({cx, cy});
      }
    }
  }
  return;
}

int main()
{
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &board[i][j]);
    }
  }

  int time = -1;
  while (1)
  {
    time += 1;
    int ground = 0;
    memset(check, false, sizeof(check));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] > 0 && !check[i][j])
        {
          bfs(i, j);
          ground += 1; // 컴포넌트를 세어줌(= 땅덩어리, BFS 알고리즘 용어)
        }
      }
    }
    // 모든 칸에 대해서 덩어리가 2개 이상으로 분리되지 않는지 확인
    if (ground >= 2)
    {
      printf("%d", time);
      break;
    }
    else if (ground == 0)
    {
      printf("0");
      break;
    }
  }
  return 0;
}
