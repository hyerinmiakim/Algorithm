#include <string>
#include <vector>
#include <cmath>
#include <stdio.h>
#define min(a,b) (a<b?a:b)
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int> num = numbers;
    int left = 10, right = 12;
    for (int i = 0; i < num.size(); i++)
    {
        if(num[i] == 1 || num[i] == 4 || num[i] == 7)
        {
            answer += 'L';
            left = num[i];
        }
            
        else if(num[i] == 3 || num[i] == 6 || num[i] == 9)
        {
            answer += 'R';
            right = num[i];
        }
        else
        {
            if(num[i] == 0) num[i] = 11;
            int R = abs(num[i] - right);
            int L = abs(num[i] - left);
            //if(R%3 == 0) R = R/3;
            //if(L%3 == 0) L = L/3;
            
            R = (R / 3) + (R % 3);
            L = (L / 3) + (L % 3);
            printf("%d : L=%d, R=%d\n", num[i], left, right);
            if(L == R)
            {
            	if(hand == "right")
            	{
            		answer += 'R';
            		right = num[i];
        		}
                else
                {
            		answer += 'L';
            		left = num[i];
        		} 
            }
            else if(min(L,R) == L)
            {
            	answer += 'L';
            	left = num[i];
        	}
            else
            {
            	answer += 'R';
            	right = num[i];
        	}
        }
    }
    printf("%s", answer.c_str());
    return answer;
}