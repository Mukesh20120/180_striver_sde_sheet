//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //lets create the adj vector
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //now we need to make a priority queue min
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //now push our source
        pq.push({1,0});
        vector<int>dist(n+1,1e9),parents(n+1);
        for(int i=0;i<=n;i++)
          parents[i]=i;
          
        dist[1]=0;
        while(!pq.empty()){
            int node=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            for(auto &it: adj[node]){
                if(x+it.second<dist[it.first]){
                    dist[it.first]=x+it.second;
                    pq.push({it.first,dist[it.first]});
                    parents[it.first]=node;
                }
            }
        }
        if(dist[n]==1e9)return {-1};
        int i=n;
        vector<int>res;
        while(parents[i]!=i){
            res.push_back(i);
            i=parents[i];
        }
        res.push_back(i);
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends