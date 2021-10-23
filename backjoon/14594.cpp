#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n, m;
  
  scanf("%d%d", &n, &m);
  int room[n+1];
  vector<pair<int, int> > ans;
  
  for(int i = 1; i <= n ; i++)
    room[i] = i;
  
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ans.push_back({a, b});
  }
  sort(ans.begin(), ans.end());

  for(int i = 0; i < ans.size(); i++) {
    int a = ans[i].first;
    int b = ans[i].second;
    
    for(int j = a; j <= b; j++) 
      room[j] = room[a];
  }

  int cnt = room[0];
  int answer = 0;
  for(int i = 1; i <= n; i++) {
    if(cnt != room[i]) {
      answer++;
      cnt = room[i];
    }
  }
  printf("%d", answer);
  return 0;
}
