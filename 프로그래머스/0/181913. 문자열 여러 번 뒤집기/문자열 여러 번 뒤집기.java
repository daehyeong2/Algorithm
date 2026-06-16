class Solution {
    public String solution(String my_string, int[][] queries) {
        String answer = "";
        char[] charArray = my_string.toCharArray();
        for(int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            for(int j = 0; j <= ((end-start)/2); j++) {
                char a = charArray[start+j];
                char b = charArray[end-j];
                charArray[start+j] = b;
                charArray[end-j] = a;
            }
        }
        for(char c : charArray) {
            answer += c;
        }
        return answer;
    }
}