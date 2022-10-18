class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return "";
        string ans=strs[0],cur;
        for(int i=1;i<n;i++){
             cur="";
            int j=0;
            int la=ans.length(),ls=strs[i].length();
            while(j<la && j<ls && ans[j]==strs[i][j]){
                cur.push_back(ans[j]);
                j++;
            }
            ans=cur;
        }
        return ans;
    }
};