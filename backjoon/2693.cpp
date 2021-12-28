#include <stdio.h>
#include <algorithm>
using namespace std;
// 12:07
int main(){
  int t; 
  scanf("%d", &t);
  while(t--) {
    int arr[11] = {0, };
    for(int i = 0; i < 10; i++) {
      scanf("%d", &arr[i]);
    }
    sort(arr, arr + 10);
    printf("%d\n", arr[7]);
  }
  return 0;
}
