class Solution {
    public int solution(int[] num_list) {
        int a = num_list[0];
        double b = num_list[0];
        for(int i = 1; i < num_list.length; i++) {
            a *= num_list[i];
            b += num_list[i];
        }
        b = Math.pow(b, 2);
        return a > b ? 0 : 1;
    }
}