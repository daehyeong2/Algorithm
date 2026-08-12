class Solution {
    public int solution(String my_string, String is_suffix) {
        int answer = 0;
        for(int i = 0; i < my_string.length(); i++) {
            String cur = my_string.substring(i);
            if(cur.equals(is_suffix)) {
                answer = 1;
                break;
            }
        }
        return answer;
    }
}