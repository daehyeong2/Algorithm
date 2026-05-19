import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public ArrayList<Integer> solution(int l, int r) {
        ArrayList<Integer> answer = new ArrayList<>();
        for(int i = l; i <= r; i++) {
            String s = String.valueOf(i);
            boolean flag = false;
            for(int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if(c != '5' && c != '0') {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            answer.add(i);
        }
        if(answer.isEmpty()) answer.add(-1);
        return answer;
    }
}