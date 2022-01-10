#include <stdio.h>
#include <algorithm>
using namespace std;
// 19:21
int arr[100001];
int main(){
  int n; 
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  
  int left = 0, right = n-1;
  int answer = 0;
  // 1 4 2 5
  while(left <= right) {
    int able = ((right - left)-1) * min(arr[left], arr[right]);
    if(arr[left] < arr[right]) left += 1;
    else right -= 1;

    answer = max(answer, able);
  }
  printf("%d", answer);
  return 0;
}
