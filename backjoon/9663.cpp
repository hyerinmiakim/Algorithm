#include <stdio.h>
#include <stdlib.h>
using namespace std;
// n-queen
int n, cnt; 
int board[17];  //{각 행마다 퀸이 놓인 열의 수 저장}

bool promissing(int _row) {

  for(int i = 0; i < _row; i++) {
    // 이전 행에서
    // 같은 열에 위치하거나, 대각선에 위치한 행이 있다면(행/열끼리의 차가 같다(기울기가 1로 증가율이 같다면))
    if(board[_row] == board[i] || _row - i == abs(board[_row] - board[i])) return false;
  }
  return true;
}

void nqueen(int row) {
  // 마지막 행 까지 도달했다면 N개의 퀸을 다 놓을 수 있다는 것으로 cnt 증가
  if(row == n) {
    cnt++;
    return;
  }

  // 현재 행에 대해서 0 ~ n-1 까지의 열에 위치해본다.
  for(int i = 0; i < n; i++) {
    board[row] = i;
    if(promissing(row)) nqueen(row+1);
  }
}
int main(){
  scanf("%d", &n);
  nqueen(0);
  printf("%d", cnt);
  return 0;
}
