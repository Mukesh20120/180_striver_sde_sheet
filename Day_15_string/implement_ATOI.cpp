class Solution {
public:
    int myAtoi(string s) {
       int i=0,ans=0;
        int n=s.length();
      //remove white space 
        while(i<n && s[i]==' ')
            i++;
        int sign=1;
       if(i>=n)return 0;
        if(s[i]=='-' || s[i]=='+'){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
         if(i>=n)return 0;
        for(;i<n && s[i]-'0'>=0 && s[i]-'0'<=9;i++){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]-'0'>INT_MAX%10))
                return sign==1?INT_MAX:INT_MIN;
            ans=ans*10+(s[i]-'0');
        }
        return ans*sign;
    }
};