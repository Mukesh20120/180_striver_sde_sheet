class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        string ans="";
        while(i<n){
        if(s[i]!=' '){
            int j=i;
            string t="";
            while(j<n && s[j]!=' '){
               t+=s[j];
                j++;
            }
            ans=t+" "+ans;
            i=j;
           }
            else
                i++;
        }
        ans.pop_back();
        return ans;
    }
};