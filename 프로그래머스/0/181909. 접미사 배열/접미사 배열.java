import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<String> solution(String my_string) {
        List<String> answer = new ArrayList<>();
        for(int i = 0; i < my_string.length(); i++){
            String cur = my_string.substring(i);
            answer.add(cur);
        }
        answer.sort(null);
        return answer;
    }
}