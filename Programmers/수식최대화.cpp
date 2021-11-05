#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> number; // 숫자
string oper;   // 기호만
void parsingString(string expression) {
    string num;
    for (int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            number.push_back(stoll(num));
            num = "";
            oper.push_back(expression[i]);	
        }
        else
            num += expression[i];
    }
    number.push_back(stoll(num));
}

long long solution(string expression) {
    long long answer = 0;
    string opcode = "*+-";
    parsingString(expression);
    
    do {
        vector <long long> tmpNum = number; // 숫자
        string tmpOper = oper;   // 기호만
        for(char op : opcode)
        {
            for(int j = 0; j < tmpOper.size(); j++)
        	{
            	if(tmpOper[j] == op) // 기호
                {
                    long long result;
                    // 숫자 찾는다 
                    
                    if(op == '+') result = tmpNum[j] + tmpNum[j+1];
                    else if(op == '-') result = tmpNum[j] - tmpNum[j+1];
                    else if(op == '*') result = tmpNum[j] * tmpNum[j+1];
                    // 위치 찾음.
                    tmpNum[j] = result;
                    tmpNum.erase(tmpNum.begin() + j + 1);
                    tmpOper.erase(tmpOper.begin() + j);
                    j--;
                }
        	}
        }
        answer = max(answer, abs(tmpNum.front()));
        
    } while(next_permutation(opcode.begin(), opcode.end()));
    
    
    return answer;
}