import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> solution(String[] intStrs, int k, int s, int l) {
        List<Integer> answer = new ArrayList();
        for(int i = 0; i < intStrs.length; i++) {
            String cur = intStrs[i];
            int num = Integer.parseInt(cur.substring(s, s+l));
            if(num > k) {
                answer.add(num);
            }
        }
        return answer;
    }
}