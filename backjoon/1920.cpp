#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[100001];
bool bin_search(int left, int right, int search) {
    int mid = (left + right)/2;

    if(left > right)
      return false;

    if(search == arr[mid])
      return true;
    else {
      if(search < arr[mid]) {
        return bin_search(left, mid-1, search);
      }
      else if(search > arr[mid]) {
        return bin_search(mid+1, right, search);
      }
    }

  return false;

}

int main() {
  int n, m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort (arr, arr+n);

  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    int search;
    scanf("%d", &search);
    if(bin_search(0, n-1, search))  printf("1\n");
    else printf("0\n");
  }
  return 0;
}