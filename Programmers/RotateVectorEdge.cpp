#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int board[101][101];
vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
  vector<int> answer;

  for (int i = 1; i <= rows; i++)
    for (int j = 1; j <= columns; j++)
      board[i][j] = ((i - 1) * columns) + j;

  for (int i = 0; i < queries.size(); i++)
  {
    int x1 = queries[i][0];
    int y1 = queries[i][1];
    int x2 = queries[i][2];
    int y2 = queries[i][3];

    pair<int, int> x = {x1, y1};
    int id = 0;
    vector<int> tmp;
    int n = 0;
    int cur, next;
    cur = board[x.first][x.second];
    while (id < 2 * ((x2 - x1) + (y2 - y1)))
    {
      int cx = x.first + way[n][0];
      int cy = x.second + way[n][1];
      if (cx >= x1 && cx <= x2 && cy >= y1 && cy <= y2)
      {
        next = board[cx][cy];
        board[cx][cy] = cur;
        x.first = cx;
        x.second = cy;
        tmp.push_back(board[cx][cy]);
        //printf("%d,%d is %d\n", cx, cy, board[cx][cy]);
        cur = next;
        id++;
      }
      else
        n++;
    }

    sort(tmp.begin(), tmp.end());
    answer.push_back(tmp.front());
  }

  return answer;
}
