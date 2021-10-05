#include <stdio.h>
#include <map>
using namespace std;

int main()
{
  int n, m;
  map<int, int> mp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int id;
    scanf("%d", &id);
    mp[id] = i;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    int id;
    scanf("%d", &id);
    if (mp.find(id) != mp.end())
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}