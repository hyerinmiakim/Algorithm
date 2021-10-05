#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > vec;

/*
bool compare (pair<int, int> a, pair<int, int> b)
{
  return a.second < b.second;
}*/
int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vec.push_back(make_pair(x, y));
  }

  sort(vec.begin(), vec.end());
  for(auto x : vec)
    cout << x.first << " " << x.second << "\n";
  return 0;
}