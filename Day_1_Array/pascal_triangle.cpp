class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(n==1)
             return ans;
        for(int i=2;i<=n;i++){
            vector<int>level(i);
            level[0]=level[i-1]=1;
            for(int j=1;j<i-1;j++){
                level[j]=ans[i-2][j-1]+ans[i-2][j];
            }
            ans.push_back(level);
        }
        return ans;
    }
};