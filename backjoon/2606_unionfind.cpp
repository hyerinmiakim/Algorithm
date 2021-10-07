#include <stdio.h>
using namespace std;
int cnt = 0;
int root[101];

int FindRoot(int start)
{
  if(start == root[start])
    return start;
  else
    return root[start] = FindRoot(root[start]);
}
void Union(int a, int b)
{
  a = FindRoot(a);
  b = FindRoot(b);

  if (a != b) {
    root[b] = a;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n;i++)  // must be started from 1 cuzof #LINE 34
    root[i] = i;

  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    Union(a, b);
  }
  
  int realRoot = FindRoot(1);
  for(int i = 2; i <= n; i++) {
    if(FindRoot(i) == realRoot) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}