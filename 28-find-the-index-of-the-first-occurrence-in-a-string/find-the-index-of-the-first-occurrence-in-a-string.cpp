class Solution {
public:
    int strStr(string h, string ne) {
        // size_t i = h.find(ne);
        // return i;
        // if(!h.find(ne)){
        //     return -1;
        // }
        
        int n = h.size();
        int m = ne.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (h[i] == ne[j])
            {
                j++;
                if (j == m)
                {
                    return i - m + 1;
                }
            }
            else
            {
                i = i - j;
                j = 0;
            }
        }
        return -1;
    }
};