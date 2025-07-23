class Solution {
    public int maximumGain(String s, int x, int y) {
        char[] chars = s.toCharArray();
        int tot = 0, a = 0, b = 0;
        int first = x > y ? 'a' : 'b';
        int second = x > y ? 'b' : 'a';
        int max = Math.max(x, y);
        int min = Math.min(x, y);
        for(char c: chars) {
            if(c == first) {
                a++;
            } else if (c == second) {
                if(a > 0) {
                    a--;
                    tot += max;
                } else {
                    b++;
                }
            } else {
                tot += Math.min(a, b) * min;
                a = b = 0;
            }
        }
        return tot + Math.min(a, b) * min;
    }
}