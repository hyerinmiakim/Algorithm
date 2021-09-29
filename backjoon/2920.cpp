#include <iostream>
using namespace std;
int main()
{
  int arr[9] = {0};
  int flag = 0;
  int flag2 = 0;

  for(int i = 0; i < 8; i++)
    cin >> arr[i];

  for(int i = 1; i < 8; i++) {
    if (arr[i-1] - arr[i] == 1) {
      flag += 1;
    }
    else if (arr[i-1] - arr[i] == -1) {
      flag2 += 1;
    }
    else if (arr[i-1] - arr[i] > 1 || arr[i-1] - arr[i] > -1)
      continue;
  }
  if(flag2 == 7)
    cout << "ascending";
  else if (flag == 7)
    cout << "descending";
  else {
    cout << "mixed";
  }
  return 0;
}