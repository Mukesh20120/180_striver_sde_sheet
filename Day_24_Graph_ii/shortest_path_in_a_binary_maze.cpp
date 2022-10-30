//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> d) {
       queue<pair<int,pair<int,int>>>q;
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>dist(n,vector<int>(m,1e9));
       q.push({0,{s.first,s.second}});
       int di[4]={-1,1,0,0};
       int dj[4]={0,0,-1,1};
       while(!q.empty()){
           int ans=q.front().first;
           int r=q.front().second.first;
           int c=q.front().second.second;
           if(r==d.first && c==d.second)
                     return ans;
           q.pop();
           for(int i=0;i<4;i++){
               int nr=di[i]+r;
               int nc=dj[i]+c;
               if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && dist[nr][nc]>ans+1){
                   dist[nr][nc]=ans+1;
                   q.push({dist[nr][nc],{nr,nc}});
               }
           }
       }
       return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends