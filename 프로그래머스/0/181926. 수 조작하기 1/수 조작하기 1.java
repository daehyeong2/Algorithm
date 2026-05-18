class Solution {
    public int solution(int n, String control) {
        int answer = n;
        for(int i = 0; i < control.length(); i++) {
            String key = String.valueOf(control.charAt(i));
            if(key.equals("w")) {
                answer += 1;
            } else if (key.equals("s")) {
                answer -= 1;
            } else if (key.equals("d")) {
                answer += 10;
            } else if (key.equals("a")) {
                answer -= 10;
            }
        }
        return answer;
    }
}