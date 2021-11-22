#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, k;
  vector<int> vec;
  scanf("%d %d", &n, &k);

  for(int i = 1; i <= n; i++) {
    if(n % i == 0)  vec.push_back(i);
  }

  sort(vec.begin(), vec.end());
  printf("%d", vec[k-1]);

  return 0;
}
