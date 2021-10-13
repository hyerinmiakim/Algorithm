#include <stdio.h>
#include <vector>
using namespace std;

int A, B, N, M;
vector<pair<pair <int, int>, int> > robot;  // 값을 저장
int road[4][2] = {{1, 0}, {0,-1}, {-1, 0}, {0,1}}; //E,S,W,N
int board[102][102];  // 배열로서 인덱싱

int main() {
  scanf("%d %d", &A, &B);
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) {
    int a,b,dir;
		char c;
    scanf("%d %d %c", &a, &b, &c);
    pair<int, int> tmp = make_pair(a, b);
    if(c == 'E')
      dir = 0;
    else if(c == 'S')
      dir = 1;
    if(c == 'W')
      dir = 2;
    if(c == 'N')
      dir = 3;
    robot.push_back(make_pair(tmp, dir));
    board[b][a] = i;
  }
  for(int i = 0; i < M; i++) {
    int robo, time;
    char way;
    scanf("%d %c %d", &robo, &way, &time);
    
    // 직진
    if (way == 'F') {
        pair<int, int> pos = robot[robo-1].first;
				int dir = robot[robo-1].second;
        int cx = pos.first;
        int cy = pos.second;

        while(time--) {
          cx = cx + road[dir][0];
          cy = cy + road[dir][1];
          if(board[cy][cx] != 0) {
            printf("Robot %d crashes into robot %d\n", robo, board[cy][cx]);
            return 0;
          }
          if(cx > A || cx <= 0 || cy > B || cy <= 0) {
            printf("Robot %d crashes into the wall\n", robo);
            return 0;
          }
        }
        board[cy][cx] = robo;
        board[robot[robo-1].first.second][robot[robo-1].first.first] = 0;
        robot[robo-1].first.first = cx;
        robot[robo-1].first.second = cy;
    }

		// 회전
    else if (way == 'L') {
        while(time--) {
          robot[robo-1].second--;
          if(robot[robo-1].second < 0)
            robot[robo-1].second = 3;
        }
    }
    else if (way == 'R') {
        while(time--) {
          robot[robo-1].second++;
          if(robot[robo-1].second > 3)
            robot[robo-1].second = 0;
        }
    }
  }
  printf("OK\n");
  return 0;
}