import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
        ArrayList<String> myans = new ArrayList<String>();
        Map<String, String> map = new HashMap<String, String>();
        
        for(int i = 0; i < record.length; i++)
        {
            String[] words = record[i].split("\\s+");
            if(words.length <= 2)
                continue;
        
         	if(map.get(words[1]) != words[2]) 
                map.put(words[1],words[2]);
        }

        for(int i = 0; i < record.length; i++)
        {
            String[] word2 = record[i].split("\\s+");
            if(word2[0].equals("Change"))
                continue;
                
            /* find user id in map */
            String s = map.get(word2[1]);
            if(s==null)
                continue;
            
           	if(word2[0].equals("Enter"))
            	myans.add(s + "님이 들어왔습니다.");  
            else if(word2[0].equals("Leave"))
                myans.add(s + "님이 나갔습니다.");
        }
        
        answer = new String[myans.size()];
        myans.toArray(answer);
        return answer;
    }
}