//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& nums) {
        //we can do this questio by two method 
        //using djistra algo and recursion
        priority_queue<pair<int,pair<int,int>>
        ,vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>>pq;
      
      int n=nums.size();
      int m=nums[0].size();
      
      vector<vector<int>>dist(n,vector<int>(m,1e9));
      
      pq.push({0,{0,0}});
      int di[4]={-1,1,0,0};
      int dj[4]={0,0,-1,1};
      int ans=INT_MIN;
      while(!pq.empty()){
          int cost=pq.top().first;
          int x=pq.top().second.first;
          int y=pq.top().second.second;
          
          pq.pop();
          
          if(x==n-1 && y==m-1)
            return cost;
          
          for(int i=0;i<4;i++){
              int nx=di[i]+x;
              int ny=dj[i]+y;
              //checking boundary case
              if(nx>=0 && ny>=0 && nx<n && ny<m){
                  int newcost=max(cost,abs(nums[x][y]-nums[nx][ny]));
                 if(newcost<dist[nx][ny]){
                     dist[nx][ny]=newcost;
                     pq.push({newcost,{nx,ny}});
                 }
              }
          }
      }
    return -1;  
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends