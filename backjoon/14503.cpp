#include <iostream>
#include <stack>
using namespace std;

int N, M;
int r, c, way;
int board[51][51];
pair<pair<int, int>, int> Left;
//char dir[4] = {'N', 'E', 'S', 'W'};                   
int point[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // N, E, S, W
int main()
{
  int idx = 0;
  int clean = 1;

  cin >> N >> M;
  cin >> r >> c >> way;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> board[i][j];
    }
  }

  Left = {{r, c}, way}; //(현재 시작 위치, 방향)
  board[r][c] = 2;

  while (true)
  {
    pair<int, int> tmp = Left.first;
    int op = Left.second;
    
    int stock = 0;
    bool stockedFlag = true;
    int nextop, nextx, nexty;
    while(stock < 4)
    {
      nextop = (op + 3) % 4;
      nextx = tmp.first + point[nextop][0];  //현재 방향에서의 왼쪽 x 좌표
      nexty = tmp.second + point[nextop][1]; //현재 방향에서의 왼쪽 y 좌표
      
      if (nextx < N && nextx > 0 && nexty < M && nexty > 0) // 범위안?
      {
        if (board[nextx][nexty] == 0) // 청소할 수 있음.
        {
          stockedFlag = false;
          break;
        }
      }
      op = nextop;
      stock++;
    }
    
    // 청소를 하고 나온 경우
    if(!stockedFlag) {
      board[nextx][nexty] = 2;
      op = nextop;
      clean += 1;
    }
    // 청소를 하나도 못했을 경우 == 현재 방향에서 후진한다.
    if (stockedFlag && stock >= 4) {
      nextop = (op + 2) % 4;
      nextx = tmp.first + point[nextop][0];  //현재 방향에서의 왼쪽 x 좌표
      nexty = tmp.second + point[nextop][1]; //현재 방향에서의 왼쪽 y 좌표
      
      if (nextx >= N || nextx < 0 || nexty >= M || nexty < 0 || board[nextx][nexty] == 1)
        break;
    }
    Left = {{nextx, nexty}, op};
  }

#if 0
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
#endif
  printf("clean : %d", clean);
  return 0;
}