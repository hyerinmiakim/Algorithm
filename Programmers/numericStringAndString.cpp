#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
map<string, int> m;

int solution(string s) {
    int answer = 0;
    int tmp = 0;
    string myans = "";
#if 1
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        if(!isdigit(s[i]))
        {
            str += s[i];
            if (m.find(str) != m.end())
            {
                myans += to_string(m[str]);
                str = "";
            }
        }
        else
            myans += s[i];
    }
#else
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            myans += s[i];
            continue;
        }
        switch(s[i])
        {
            case 'o':
                myans += '1';
                i+= 2;
                break;
            case 'z':
                myans += '0';
                i += 3;
                break;
            case 't':
                if(s[i+1] == 'w')
                {
                    myans += '2';
                    i += 2;
                }
                else if(s[i+1] == 'h')
                {
                    myans += '3';
                    i += 4;
                }
                break;
            case 'f':
                if(s[i+1] == 'o')
                {
                    myans += '4';
                    i += 3;
                }
                else if(s[i+1] == 'i')
                {
                    myans += '5';
                    i += 3;
                }
                break;
            case 's':
                if(s[i+1] == 'i')
                {
                    myans += '6';
                    i += 2;
                }
                else if(s[i+1] == 'e')
                {
                    myans += '7';
                    i += 4;
                }
                break;
            case 'e':
                myans += '8';
                i += 4;
                break;    
            case 'n':
                myans += '9';
                i += 3;
                break;     
             
        }
    }
#endif
    answer = stoi(myans);
    return answer;
    
}