class Solution {
    public int solution(String number) {
        int answer = 0;
        char[] charArray = number.toCharArray();
        for(char c : charArray) {
            int num = c - '0';
            answer += num;
        }
        answer = answer % 9;
        return answer;
    }
}