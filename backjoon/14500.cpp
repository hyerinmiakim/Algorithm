#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, answer;
int board[501][501];
int pos[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
bool check[501][501];

void tetromino(int x, int y, int sum, int depth) {
  check[x][y] = true;
  if(depth == 3) {
    answer = max(answer, sum);
    return;
  }
  for(int i = 0; i < 4; i++) {
    int cx = x + pos[i][0];
    int cy = y + pos[i][1];
    if(cx >= N || cx < 0 || cy >= M || cy < 0) continue;
    if(check[cx][cy]) continue;
    tetromino(cx, cy, sum + board[cx][cy], depth + 1);
    check[cx][cy] = false;  // 다른 방향에서 시작했을 때에도 걸리게 하기 위해
  }
  return;
}
void extraTetromino(int x, int y) {
  // ㅗ
  if(x - 1 >= 0 && y + 1 < M) {
    answer = max(answer, board[x][y] + board[x][y-1] + board[x-1][y] + board[x][y+1]);
  }
  // ㅏ
  if(x-1 >= 0 && x + 1 < N && y + 1 < M) {
    answer = max(answer, board[x][y] + board[x-1][y] + board[x][y+1] + board[x+1][y]);
  }
  // ㅜ
  if(x + 1 < N && y + 1 < M && y-1 >= 0) {
    answer = max(answer, board[x][y] + board[x][y-1] + board[x+1][y] + board[x][y+1]);
  }
  // ㅓ
  if(x - 1 >= 0 && x+1 < N && y - 1 >= 0) {
    answer = max(answer, board[x][y] + board[x-1][y] + board[x][y-1] + board[x+1][y]);
  }
}
int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++)
      scanf("%d", &board[i][j]);
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++)
    {
      memset(check, 0, sizeof(check));
      tetromino(i, j, board[i][j], 0);
      extraTetromino(i, j);
    }
  }
  printf("%d\n", answer);
  return 0;
}
