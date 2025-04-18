class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string say = countAndSay(n-1);
        string ans="";
        for(int i=0;i<say.length();i++){
            char ch = say[i];
            int count =1;
            while(i<say.length()-1 && say[i+1]==ch){
                count +=1;
                i++;
            }
            ans+=to_string(count)+string(1,ch);


        }
        return ans;
    }
};