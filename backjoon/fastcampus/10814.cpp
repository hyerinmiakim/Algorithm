#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, string> > vec;

bool compare (pair<int, string> a,pair<int, string> b)
{
  return a.first < b.first;
}
int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int age;
    string name;
    cin >> age >> name;
    vec.push_back(make_pair(age, name));
  }

  stable_sort(vec.begin(), vec.end(), compare);
  for(auto x : vec)
    cout << x.first << " " << x.second << "\n";
  return 0;
}