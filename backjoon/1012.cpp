#include <stdio.h>
#include <cstring>
using namespace std;
// 16:20
int board[53][53];
bool check[53][53];
int way[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int row, col;
int cnt = 0;

void dfs(int x, int y) {
  check[x][y] = true;
  cnt += 1;
  for(int i = 0; i < 4; i++) {
    int cx = x + way[i][0];
    int cy = y + way[i][1];
    if(cx < 0 || cx >= row || cy < 0 || cy >= col) continue;
    if(check[cx][cy] == false && board[cx][cy])  {
      dfs(cx, cy);
    }
  }
 
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    memset(board, 0, sizeof(board));
    memset(check, false, sizeof(check));
    int num, slime = 0;
    scanf("%d%d%d", &row, &col, &num);
    for(int i = 0; i < num; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      board[x][y] = 1;
    }
    
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        if(check[i][j] == false && board[i][j]) {
          cnt = 0;
          dfs(i, j);
          if(cnt > 0) slime+=1;
        }
      }
    }
    printf("%d\n", slime);
  }
  return 0;
}
