#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string myid = "";
    
    transform (new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    for (int i = 0; i < new_id.size(); i++)
    {
        if (isalpha(new_id[i]) || isdigit(new_id[i]))
            myid.push_back(new_id[i]);
        
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            if (new_id[i] == '.')
        	{
            	if(!myid.empty() && myid.back() == '.')
                	continue;
        	}
            myid.push_back(new_id[i]);
        }
    }

    if (myid.front() == '.')
        myid.erase(myid.begin());
    
    if (myid.back() == '.')
        myid.pop_back();
    
    if (myid.empty())
        myid.push_back('a');
    
    /* size */
    while (myid.size() >= 16)
    {
        myid.pop_back();
        if(myid.back() == '.')
        	myid.pop_back();
    }

    if (myid.size() <= 2)
   		myid.insert(myid.end(), 3 - myid.size(), myid.back());
    
    answer = myid;
    cout << answer << endl;
    return answer;
}