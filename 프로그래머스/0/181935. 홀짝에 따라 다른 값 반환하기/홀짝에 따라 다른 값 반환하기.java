class Solution {
    public int solution(int n) {
        int answer = 0;
        for(int i = 1; i <= n; i++) {
            if(n%2 == i%2) answer += i%2 == 0 ? i*i : i;
        }
        return answer;
    }
}