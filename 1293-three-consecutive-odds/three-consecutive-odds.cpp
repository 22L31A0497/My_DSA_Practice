class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count =0;
        if(arr.size()<3)return false;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=i;j<i+3;j++){
               if(arr[j]%2!=0){
                count++;
            }
            }
            if(count == 3)return true;
            count =0;
           
        }
        return false;
    }
};