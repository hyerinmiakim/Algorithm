#include <stdio.h>
using namespace std;

int func(int n) {
  if(n <= 1)  return 1;
  return n * func(n-1);
}
int main(){
  int n; 
  scanf("%d", &n);
  int ret = func(n);
  printf("%d", ret);
  return 0;
}
