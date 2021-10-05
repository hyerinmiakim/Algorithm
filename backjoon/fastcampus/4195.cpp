#include <stdio.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

int parent[200001];
int child[200001];
char one[21], two[21];

int Findroot(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = Findroot(parent[x]);
}
void unionroot(int x, int y)
{
  x = Findroot(x);
  y = Findroot(y);

  if (x != y)
  {
    parent[y] = x;
    child[x] += child[y]; //자식 추가
  }
}
int main()
{
  int n, m;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &m);
    map<string, int> mp; // (이름 , 순서)
    int cnt = 1;

    /* 한 네트워크 당 두 사람이기 때문에, 사람 별 부모/자식배열 생성 */
    for (int j = 1; j <= 2 * m; j++)
    {
      parent[j] = j; //현재 값의 부모는 자기 자신
      child[j] = 1; //자식 수
    }

    for (int j = 0; j < m; j++)
    {
      string x, y;
      scanf("%s %s", &one, &two);

      // one/two 를 key로 가진 갯수 리턴 (1 or 0)
      /* cnt: 친구 네트워크에 새로 추가된 순서 == 그래프의 깊이 */
      if (mp.count(one) == 0)
        mp[one] = cnt++;
      if (mp.count(two) == 0)
        mp[two] = cnt++;

      /* 새로 추가된 아이들의 root를 찾고, 합쳐줌 */
      unionroot(mp[one], mp[two]);
      /* root의 자식 수를 출력 == 현재 자신이 추가된 위치 */
      printf("%d\n", child[Findroot(mp[one])]);
    }
  }
  return 0;
}