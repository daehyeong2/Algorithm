class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        int[] answer = new int[queries.length];
        for(int i = 0; i < queries.length; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            int k = queries[i][2];
            
            int ret = -1;
            for(int j = s; j <= e; j++) {
                if(arr[j] <= k) continue;
                if(ret == -1 || ret > arr[j]) ret = arr[j];
            }
            answer[i] = ret;
        }
        return answer;
    }
}