class Solution {
public:
    int myAtoi(string s) {
       if(s.length()==0)return 0;
       int i=0;
       while(i<s.size() && s[i]==' '){
        i++;
       }
       s = s.substr(i);
       int sign =+1;
       long ans=0;
       if(s[0]=='-')sign=-1;
       int max=INT_MAX,min=INT_MIN;
       if(s[0]=='+' ||s[0]=='-'){
        i=1;
       }else i=0;
       while(i<s.length()){
        if(s[0]==' '||!isdigit(s[i]))break;
        ans= ans*10+s[i]-'0';
        if(sign==-1 && -1*ans<min)return min;
        if(sign==+1 && 1*ans>max)return max;
        i++;
       }
      return (int)(sign*ans);
    }
};