#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

long long A, B;
int ret;
#if 0
int way[2] = {2, 1};
bool check[1000000001];

bool bfs() {
  queue<long long> que;
  que.push(A);

  while(!que.empty()) {
    long long start = que.front();
    que.pop();

    long long a = start * way[0];
    long long b = stoll(to_string((int)start) + to_string(way[1]));

    if(a < B && check[a] == 0) {
      check[a] = true;
      que.push(a);
      printf("push a : %lld, ", a);
    }
    if (b < B && check[b] == 0) {
      check[b] = true;
      que.push(b);
      printf("push b : %lld, ", b);
    }
    cnt++;
    printf("current cnt: %d\n", cnt);
    if(a == B || b == B)
      return true;
  }
  return false;
}
#else
int bfs2() {
  queue<pair<long long, int> > que;
  que.push(make_pair(A, 1));
  
  while(!que.empty()) {
    long long start = que.front().first;
    int depth = que.front().second;
    que.pop();

    long long a = start * 2;
    long long b = (start * 10) + 1;

    if(a < B) {
      que.push(make_pair(a, depth + 1));
    }
    if (b < B ){
      que.push(make_pair(b, depth + 1));
    }
    
    if(a == B || b == B) {
      ret = depth + 1;
      return true;
    }
  }
  return false;
}
#endif
int main() {
  scanf("%lld %lld", &A, &B);
  //if(bfs()) printf("%ld, cnt: %d\n", logB(cnt,2), (cnt/2) + 1);
  //else printf("-1\n");
  
  // 끝자리가 1이 아닌 홀수는 만들 수 없다.
  if ((B % 10 != 1) && (B % 2 == 1)) {
    printf("-1\n");
    return 0;
  }
  if(bfs2()) printf("%d", ret);
  else printf("-1\n");

  return 0;
}