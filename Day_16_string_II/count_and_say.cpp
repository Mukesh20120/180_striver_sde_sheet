//upgrade question of string compression
class Solution {
public:
    string countAndSay(int n) {
       string ans="1";
        for(int z=2;z<=n;z++){
            int i=0,idx=0,j;
            int sz=ans.length();
            string temp="";
            while(i<sz){
                j=i;
                while(i<sz && ans[i]==ans[j])i++;
                
                string cnt=to_string(i-j);
                if(i-j>=1){
                    for(char c: cnt)
                        temp.push_back(c);
                }
                temp.push_back(ans[j]);
            }
            ans=temp;
        }
        return ans;
    }
};