//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //we will do using bfs 
        //step 1 make adj list
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //now as given all the node length is 1
        vector<int>ans(N);
        for(int i=0;i<N;i++)
           ans[i]=INT_MAX;
         ans[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty()){
            int node=q.front().first;
            int weight=q.front().second;
            q.pop();
            for(auto &it: adj[node]){
                if(weight+1<ans[it]){
                    ans[it]=weight+1;
                    q.push({it,ans[it]});
                }
            }
        }
        for(int i=0;i<N;i++)
           if(ans[i]==INT_MAX)
              ans[i]=-1;
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends