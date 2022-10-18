//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
     bool dfs(int src,int visit[],int path[],vector<int>adj[]){
         visit[src]=1;
         path[src]=1;
         for(auto it: adj[src]){
             if(visit[it]==false){
                 if(dfs(it,visit,path,adj))
                    return true;
             }
             else if(path[it])
                 return true;
         }
         path[src]=0;
         return false;
     }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        int visited[v]={0};
        int pathvisit[v]={0};
        for(int i=0;i<v;i++){
            if(visited[i]==false)
               if(dfs(i,visited,pathvisit,adj))
                  return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends