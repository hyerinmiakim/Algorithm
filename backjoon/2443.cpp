#include <stdio.h>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int len = (2*n)-1;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < len; j++) {
      if(j < i ) printf(" ");
      else if (j + i >= len)  break;
      else printf("*");
    }
    printf("\n");
  }
  return 0;
}
