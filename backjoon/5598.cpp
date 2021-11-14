#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string str;
  cin >> str;
  for(char c : str) {
    char idx;
    idx = c - 3;
    if(idx < 'A')
      idx = 'Z' - (2 - (c - 'A'));
    cout << idx;
  }
  return 0;
}
