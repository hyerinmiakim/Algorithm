#include <iostream>
#include <queue>

using namespace std;


int main()
{
  int tc, n, m;
  vector<int> vec;
  cin >> tc;

  for(int i = 0; i < tc; i++) {
    cin >> n >> m;
    priority_queue<int> pq;
    queue<pair<int, int> > que;
    for(int j = 0; j < n; j++) {
      int order;
      cin >> order;
      pq.push(order);
      que.push(make_pair(order, j));
      
    }
    int cnt = 0;
    while (!que.empty())
    {
      pair<int, int> var = que.front();
      que.pop();
      if(pq.top() == var.first) { //우선순위 비교
        cnt++;
        
        pq.pop();
        if(m == var.second)
          break;
      }
      else {
        que.push(var);
      }
    }
    vec.push_back(cnt);

  }

  for (int c : vec)
    cout << c << endl;
  return 0;
}
