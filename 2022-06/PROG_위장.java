import java.util.*;
import java.util.stream.*;

class Solution {
    private Map<String, Integer> clothMap = new HashMap<>();
    
    public int solution(String[][] clothes) {
        int answer = 1;
 
        for(String[] ary : clothes) {
            if(clothMap.containsKey(ary[1])) {
                Integer cnt = clothMap.get(ary[1]);
                cnt++;
                
                clothMap.put(ary[1], cnt);
           
            } else {
                clothMap.put(ary[1], 1);
            }

        }
        
        for(Integer cnt : clothMap.values()) 
            answer *= (cnt + 1);
        
        
   
        return answer-1;
    }
}