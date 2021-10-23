#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int root[10002]; // #1922 는 1002
vector<pair <int, pair<int, int> > > vec;
int depth;

int Findroot(int x) {
  if(root[x] == x)  return x;
  return root[x] = Findroot(root[x]);
}

void Union(int a, int b, int c) {  
  a = Findroot(a);
  b = Findroot(b);
  if(a != b) {
    root[b] = a;
    depth += c; 
  }
}
int main() {
  int v, e;
  scanf("%d%d", &v, &e);
  for(int i = 1; i <= v; i++) 
    root[i] = i;
  
  for(int i = 0; i < e; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    vec.push_back({c, {a, b}});
  }

  sort(vec.begin(), vec.end());
  for(auto a : vec) {
    int line = a.first;
    int one = a.second.first;
    int two = a.second.second;
    Union(one, two, line);
  }
  printf("%d", depth);
  return 0;
}
