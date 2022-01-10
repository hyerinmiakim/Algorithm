#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 2e9+1
// 18:34
int arr[100002];
int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int left = 0, right = 0;
  int sum = 0, answer = MAX;

  sort(arr, arr + n);
  // 1,2,3,4,5 // 3
  while(left <= right && right < n) {
    int sum = arr[right] - arr[left];

    if(sum >= m) {
      answer = min(answer, sum);
      left+=1;
    }
    else {
      right += 1;
    }
  }
  printf("%d", answer);
  return 0;
}
