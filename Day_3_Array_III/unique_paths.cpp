//recursive solution 
//we just have to go up and left and count the path 
class Solution {
public:
    int recursive(int i,int j){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        //one way is go up and other go left
        return recursive(i-1,j)+recursive(i,j-1);
    }
    
    int uniquePaths(int m, int n) {
        return recursive(m-1,n-1);
    }
};


//memoization version
class Solution {
public:
    int memorecursive(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        //one way is go up and other go left
        int up=memorecursive(i-1,j,dp);
        int left=memorecursive(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memorecursive(m-1,n-1,dp);
    }
};

//optimize above memoization version into dp version
class Solution {
public:
 
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(i==0 || j==0)
                   dp[i][j]=1;
              if(i>0 && j>0)
                  dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//more optimized above code
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,1),cur(n,0);
        //initilize 0 row and 0 col of dp
        for(int i=1;i<m;i++){
            cur[0]=1;
            for(int j=1;j<n;j++)
              cur[j]=cur[j-1]+prev[j];
         prev=cur;
        }
        return prev[n-1];
    }
};