#include <iostream>
using namespace std;
int main()
{
  int arr[9] = {0};
  bool des = true;
  bool asc = true;

  for(int i = 0; i < 8; i++)
    cin >> arr[i];

  for(int i = 1; i < 8; i++) {
    if (arr[i-1] > arr[i])
      asc = false;
    else if (arr[i-1] < arr[i])
      des = false;
  }
  if(asc == true)
    cout << "ascending";
  else if (des == true)
    cout << "descending";
  else cout << "mixed";
  return 0;
}