#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

vector<int> outdegree[501];
int indegree[501];
int timeval[501];
int build[501];

int main(){
  int n;
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  cin.ignore();
  // 건물 건설 시간, 먼저 지어져야 하는 건물 번호(없을 수도 있음), 마지막은 -1
  for(int i = 1; i <= n; i++) {
    int building, next;
    string s, str;
    //cin >> s;
    getline(cin, s);
    istringstream ss(s);
    while(ss >> str) {
      if(str == "-1") break;
      else if (timeval[i]==0) 
        timeval[i] = build[i] = stoi(str);
      else {
        int before = stoi(str);
        outdegree[before].push_back(i);
        indegree[i]+=1;
      }
    }
  }

  queue<int> que;
  for(int i = 1; i <= n; i++) {
    if(indegree[i] == 0)  que.push(i);
  }

  for(int i = 1; i <= n; i++) {
    if(que.empty()) break;
    int start = que.front();
    que.pop();
    for(int a : outdegree[start]) {
      if(build[a] < timeval[a] + build[start])  // 누적 건설시간이 {순수 건설 시간} + {start의 누적 건설시간}의 합보다 크면 갱신하지 않는다.
        build[a] = timeval[a] + build[start];
      
      indegree[a]-=1;
      if(indegree[a] == 0)  que.push(a);
    }
  }

  for(int i=1; i <= n; i++)
    cout << build[i] << "\n";
  return 0;
}

