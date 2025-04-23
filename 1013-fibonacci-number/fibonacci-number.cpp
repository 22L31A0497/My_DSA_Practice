class Solution {
public:
    int fib(int n) {
      //DP series space optamization 
      int prev =1;
      int prev2 =0;
      if (n==1)return 1;
      if(n==0)return 0;
      for(int i =2 ;i<=n;i++){
        int curr=prev +prev2;
        prev2 = prev;
        prev= curr;
      } 
      return prev;
    }
};