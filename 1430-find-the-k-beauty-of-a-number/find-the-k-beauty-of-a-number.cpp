class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count=0;
        string s=to_string(num);
        int i=0;
        int j=k-1;
        while(j<s.length()){
           int n = stoi(s.substr(i, j - i + 1));
           if(n==0){
            j++;
            i++;
            continue;
            }
           if(num%n==0)count++;
           i++;
           j++;

        }
        return count;
    }
};