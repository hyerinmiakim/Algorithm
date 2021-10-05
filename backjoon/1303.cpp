#include <stdio.h>
#include <queue>
using namespace std;

char vec[101][101];
int check[101][101];
int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 우, 아래, 좌, 상
int n, m;

int bfs(int i, int j)
{
  check[i][j] = 1;
  int cnt = 1;
  queue<pair<int, int> > que;
  que.push(make_pair(i, j));

  while (!que.empty())
  {
    pair<int, int> start = que.front();
    que.pop();
    for (int k = 0; k < 4; k++)
    {
      int cx = start.first + way[k][0];
      int cy = start.second + way[k][1];

      if (cx >= 0 && cx < m && cy >= 0 && cy < n)
      {
        if (check[cx][cy] == 0 && (vec[cx][cy] == vec[start.first][start.second]))
        {
          check[cx][cy] = 1;
          cnt = cnt + 1;
          que.push(make_pair(cx, cy));
        }
      }
    }
  }
  return cnt;
}
int main()
{
  int answer[2] = {0, 0};
  scanf("%d %d", &n, &m);
 
  for(int i = 0; i < m; i++) {
      scanf("%s", &vec[i]);
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(check[i][j] == 0 && vec[i][j] != '\0') {
        int cnt = bfs(i, j);
        if(vec[i][j] == 'W')  answer[0] += (cnt * cnt);
        else  answer[1] += (cnt * cnt);
      }
    }
  }

  for(int i : answer)
    printf("%d ", i);
  return 0;
}