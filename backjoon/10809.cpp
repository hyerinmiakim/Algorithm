#include <iostream>
#include <cstring>
using namespace std;

int alpha[27];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(alpha, -1, sizeof(alpha));
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); i++) {
    if(alpha[str[i] - 'a'] == -1) {
      alpha[str[i] - 'a'] = i;
    }
    
  }

  for (int i = 0; i < 26; i++)
    printf("%d ", alpha[i]);
  return 0;
}
