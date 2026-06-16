class Solution {
    public String solution(String my_string, int[] index_list) {
        String answer = "";
        char[] charList = my_string.toCharArray();
        for(int i : index_list) {
            answer += charList[i];
        }
        return answer;
    }
}