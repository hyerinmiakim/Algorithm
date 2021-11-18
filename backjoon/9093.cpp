#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  while(n--) {
    string str;
    string tmp;
    getline(cin, str);
  
    istringstream iss(str);
    while(iss >> tmp) {
      int len = tmp.size();
      for(int i = len-1; i >= 0; i--) {
        cout << tmp[i];
      }
      cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
