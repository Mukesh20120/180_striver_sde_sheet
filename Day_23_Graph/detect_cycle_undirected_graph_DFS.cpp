//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
     bool dfsCycle(int src,int prnt,vector<bool>&visit,vector<int>adj[]){
         //mark visited
         visit[src]=true;
         for(auto it: adj[src]){
             if(visit[it]==false){
                 if(dfsCycle(it,src,visit,adj))
                      return true;
             }
             else if(it!=prnt)
               return true;
         }
         return false;
     }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visit(V,false);
        for(int i=0;i<V;i++){
            if(visit[i]==false){
                if(dfsCycle(i,-1,visit,adj))
                     return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends