#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<char, int>  cost;   // 재료 당 단가
map<string, int> dish;   // 메뉴 당 1개 수익

void getCostPerIngredient(vector<string> ings) {
    for(int i = 0; i < ings.size(); i++) {
        char ingr = ings[i][0];
        string pay;
        for(int j = 2; j < ings[i].size(); j++)
            pay += ings[i][j];

        cost[ingr] = stoi(pay);
    }
}

void getCostperMenu(vector<string> menu) {
    for(int i = 0; i < menu.size(); i++) {
        string cos = menu[i];
        string cnt; int space = 0;
        string food;
        for(int j = 0; j < cos.size(); j++) {

            if(cos[j] == ' ') {
                // 메뉴
                if (!space) {
                  
                    food = cnt;
                    cnt.clear();
                    space = 1; 
                }
                // 재료 & 단가
                else {
                    int pay = 0;
                    for(int k = 0; k < cnt.size(); k++) {
                        pay += cost[cnt[k]];
                    }
                    string sell = "";
                    for(int k = j+1; k < cos.size(); k++)
                        sell += cos[k];

                    int benefit = stoi(sell) - pay;
                    dish[food] = benefit;
                    break;
                }
            }
            cnt.push_back(cos[j]);
        }
    }
}
int solution(vector<string> ings, vector<string> menu, vector<string> sell) {
    int answer = 0;

    getCostPerIngredient(ings);
    getCostperMenu(menu);
    for(int i = 0; i < sell.size(); i++)
    {
        istringstream ss(sell[i]);
        string food, price;
        ss >> food >> price;
        answer += (dish[food] * stoi(price));
    }

    return answer;
}