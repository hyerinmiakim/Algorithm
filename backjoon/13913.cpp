#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
//10:00 - 16, 10:56 - 12:07
int n, k;
int check[100001];
int depth[100001];

int getNum(int num, int i)
{
  if (i == 0)
    return num - 1;
  if (i == 1)
    return num + 1;
  else return (2 * num);
}

// src 부터 dst까지 역 추척
void printNum(int src, int dst)
{
  // 시작까지
  if (src != dst)
  {
    printNum(src, check[dst]);
  }
  printf("%d ", dst);
}

int main()
{
  scanf("%d%d", &n, &k);
  memset(check, -1, sizeof(check));
  queue<int> que;
  que.push(n);
  check[n] = n;
  while (!que.empty())
  {
    int x = que.front();
    que.pop();
    for (int i = 0; i < 3; i++)
    {
      int cx = getNum(x, i);
      if (cx < 0 || cx > 100000)
        continue;
      if (check[cx] != -1)
        continue;
      check[cx] = x;
      que.push(cx);
      depth[cx] = depth[x] + 1;
    }
  }
  printf("%d\n", depth[k]);
  printNum(n, k);
  return 0;
}
