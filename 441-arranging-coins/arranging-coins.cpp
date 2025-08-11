class Solution {
public:
    int arrangeCoins(int n) {
        long long coin =n;
        int row =0;
        int i =1;
        while(coin>=i){
            coin -= i;
            row++;
            i++;
        }
        return row;
        
    }
};