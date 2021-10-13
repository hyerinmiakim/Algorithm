#include <stdio.h>
using namespace std;

int r, c, n;
char board[201][201];

void printB(char (*brd)[201]){
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      printf("%c", brd[i][j]);
    printf("\n");
  }
}
int main() {
  scanf("%d%d%d", &r, &c, &n);

  for (int i = 0; i < r; i++) {
    scanf("%s", &board[i]);
  }
  if (n % 2 == 0) {
    for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++)
        printf("O");
      printf("\n");
    }
    return 0;
  }

  char bomb[201][201] = {0, };

  for (int tc = 1; tc < n; tc += 2) {

    /* copy to bomb */
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        bomb[i][j] = board[i][j];

    /* BOMB */
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (board[i][j] == 'O') {
          if (i + 1 < r) bomb[i + 1][j] = 'O';
          if (i - 1 >= 0) bomb[i - 1][j] = 'O';
          if (j + 1 < c) bomb[i][j + 1] = 'O';
          if (j - 1 >= 0) bomb[i][j - 1] = 'O';
          
        }
      }
    }
    
    /* checked explored position */
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
        if(bomb[i][j] == 'O')
          board[i][j] = '.';
        else
          board[i][j] = 'O';
      }
  }
  printB(board);
  return 0;
}