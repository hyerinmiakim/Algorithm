#include <iostream>
using namespace std;

int n;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  int balloon, arrow = 0, arrowHeight = 0;
  for(int i = 0; i < n; i++) {
    cin >> balloon;
    if(arrowHeight < balloon) {
      arrow+=1;
      arrowHeight = balloon-1;
    }
    else {
      arrowHeight-=1;
    }
  }
  cout << arrow;
  return 0;
}
