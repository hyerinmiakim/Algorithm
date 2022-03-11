#include <iostream>
#include <queue>
#define MAX 11
//#define pii pair< pair<int, int>, pair<int, int> >
using namespace std;
int n, m;

char board[MAX][MAX];
bool check[MAX][MAX][MAX][MAX]; // {빨간공 좌표}{파란공 좌표}
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct pii {
  int rx, ry, bx, by, cnt;
};

int bfs(int redX, int redY, int blueX, int blueY) {
  int times;
  queue<pii> que;
  que.push({redX, redY, blueX, blueY, 0});
  check[redX][redY][blueX][blueY] = true;

  while(!que.empty()) {
    pii start = que.front();
    que.pop();
    if(board[start.rx][start.ry] == 'O') return start.cnt;

    for(int i = 0; i < 4; i++) {
      int crx = start.rx; //current red x
      int cry = start.ry;
      int cbx = start.bx;
      int cby = start.by;
      int moveCnt = start.cnt;
      int redMove = 0, blueMove = 0;
      
      if(crx < 0 || crx >= n || cbx < 0 || cbx >= n) continue;
      if(cry < 0 || cry >= m || cby < 0 || cby >= m) continue;
      
      // 막힐 때 까지 좌표 이동 : "다음 좌표"가 벽이 아니고 "현재 좌표"가 구멍이 아닌 경우
      while(board[crx+pos[i][0]][cry+pos[i][1]] != '#' && board[crx][cry] != 'O') {
        crx += pos[i][0];
        cry += pos[i][1];
        redMove += 1;
      }
      while(board[cbx+pos[i][0]][cby+pos[i][1]] != '#' && board[cbx][cby] != 'O') {
        cbx += pos[i][0];
        cby += pos[i][1];
        blueMove += 1;
      }

      // 실패 조건: blue공이 들어갈 경우 
      if(board[cbx][cby] == 'O') continue;

      // 빨간 공과 파란 공이 겹치는 경우, 더 많이 움직인 공을 움직인다
      if(crx == cbx && cry == cby) {
        if(redMove > blueMove) {
          crx -= pos[i][0];
          cry -= pos[i][1];
        }
        else {
          cbx -= pos[i][0];
          cby -= pos[i][1];
        }
      }
      
      if(check[crx][cry][cbx][cby]) continue;

      // 실패 조건 : 10회 이상일 때 
      if(moveCnt < 10) {
        check[crx][cry][cbx][cby] = true;
        que.push({crx, cry, cbx, cby, moveCnt + 1});
      }
    }
  }
  
  return -1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  // 기울이는 횟수를 구하는 것
  // 빨간공 탐색 후 파란공 해야함 . 이때, 홀에 들어갈 수 있으면 실패 
  int Rx, Ry, Bx, By, answer = -1;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
      if(board[i][j] == 'R') {
        Rx = i; Ry = j;
      }
      if (board[i][j] == 'B') {
        Bx = i; By = j;
      }
    }
  }
  cout << bfs(Rx, Ry, Bx, By);
 
  return 0;
}
