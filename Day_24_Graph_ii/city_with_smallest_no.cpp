//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int dt) {
                     vector<vector<int>>dist(n,vector<int>(n,1e9));
                     for(auto &it: edges){
                         int u=it[0];
                         int v=it[1];
                         int wt=it[2];
                         dist[u][v]=wt;
                         dist[v][u]=wt;
                     }
                     //making the diagonal to 0
                     for(int i=0;i<n;i++)
                         dist[i][i]=0;
                     
                     for(int k=0;k<n;k++){
                         for(int i=0;i<n;i++){
                             for(int j=0;j<n;j++){
                                 if(dist[i][k]==1e9 || dist[k][j]==1e9)
                                   continue;
                                dist[i][j]=min(dist[i][j],dist[k][j]+dist[i][k]);
                             }
                         }
                     }
                     int cntcity=n;
                     int city=0;
                     for(int i=0;i<n;i++){
                         int cnt=0;
                         for(int j=0;j<n;j++){
                             if(dist[i][j]<=dt)
                               cnt++;
                         }
                         if(cnt<=cntcity){
                             city=i;
                             cntcity=cnt;
                         }
                     }
                     return city;
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends