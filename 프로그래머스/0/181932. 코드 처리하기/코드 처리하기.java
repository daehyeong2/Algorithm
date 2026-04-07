class Solution {
    public String solution(String code) {
        String answer = "";
        boolean mode = false;
        char[] codeCharArray = code.toCharArray();
        for(int i = 0; i < code.length(); i++) {
            if(mode == false) {
                if(codeCharArray[i] == '1') {
                    mode = true;
                } else if (i % 2 == 0) {
                    answer += codeCharArray[i];
                }
            } else {
                if(codeCharArray[i] == '1') {
                    mode = false;
                } else if (i % 2 == 1) {
                    answer += codeCharArray[i];
                }
            }
        }
        return answer.length() == 0 ? "EMPTY" : answer;
    }
}