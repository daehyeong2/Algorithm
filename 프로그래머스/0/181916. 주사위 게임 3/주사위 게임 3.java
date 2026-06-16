import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int solution(int a, int b, int c, int d) {
        int answer = 0;
        Set<Integer> set = new HashSet<>(List.of(a, b, c, d));
        ArrayList<Integer> arr = new ArrayList(set);
        if (set.size() == 1) {
            answer = 1111 * arr.get(0);
        } else if(set.size() == 2) {
            if (a != b && a != c && a != d) {
                answer = (int)Math.pow(10 * b + a, 2);
            } else if(b != a && b != c && b != d) {
                answer = (int)Math.pow(10 * a + b, 2);
            } else if(c != a && c != b && c != d) {
                answer = (int)Math.pow(10 * a + c, 2);
            } else if(d != a && d != b && d != c) {
                answer = (int)Math.pow(10 * a + d, 2);
            } else {
                if(a != b) {
                    answer = (a+b) * Math.abs(a-b);
                } else if (a != c) {
                    answer = (a+c) * Math.abs(a-c);
                } else if (a != d) {
                    answer = (a+d) * Math.abs(a-d);
                }
            }
        } else if (set.size() == 3) {
            if (a == b) {
                answer = c * d;
            } else if (a == c) {
                answer = b * d;
            } else if (a == d) {
                answer = b * c;
            } else if (b == c) {
                answer = a * d;
            } else if (b == d) {
                answer = a * c;
            } else if (c == d) {
                answer = a * b;
            }
        } else {
            answer = Math.min(Math.min(Math.min(a, b), c), d);
        }
        return answer;
    }
}