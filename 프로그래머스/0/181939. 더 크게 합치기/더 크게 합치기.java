class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        int x = Integer.valueOf(String.valueOf(a) + String.valueOf(b));
        int y = Integer.valueOf(String.valueOf(b) + String.valueOf(a));
        answer = Math.max(x, y);
        return answer;
    }
}