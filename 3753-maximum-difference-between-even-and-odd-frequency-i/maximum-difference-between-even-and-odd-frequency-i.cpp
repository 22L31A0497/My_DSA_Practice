class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mpp;
        for(char ch:s){
            mpp[ch]++;
        }
        int odm=0;
        int enm=INT_MAX;
        for(const auto it:mpp){
            if(it.second%2==0){
                enm=min(enm,it.second);

            }else{
                odm = max(odm,it.second);
            }
            
        }
        return odm-enm;
    }
};