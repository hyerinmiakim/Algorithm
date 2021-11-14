#include <stdio.h>
using namespace std;

int main(){
  int mx = 0, idx;
  for(int i = 1; i <= 9; i++) {
    int num;
    scanf("%d", &num);
    if(mx < num){
      mx = num;
      idx = i;
    }
  }
  printf("%d\n%d", mx, idx);
  return 0;
}
