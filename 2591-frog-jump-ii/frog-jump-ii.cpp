class Solution {
public:
    int maxJump(vector<int>& stones) {
       int ans=0;
       for(int i=2;i<stones.size();i++){
          ans= max(ans,stones[i]-stones[i-2]);
       } 
       if(ans==0){
        return stones[1]-stones[0];
       }else{
        return ans;
       }
    }
};