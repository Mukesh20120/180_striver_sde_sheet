//whole code is same as cycle detection 
//little bit modification 
//dfs cycle detection

class Solution {
  public:
     bool dfscycle(int path[],int visited[],int check[],vector<int>adj[],int src){
         visited[src]=1;
         path[src]=1;
         for(auto &it: adj[src]){
             if(visited[it]==0 && !dfscycle(path,visited,check,adj,it))
                return false;
             else if(path[it] && visited[it])
                  return false;
         }
         check[src]=1;
         path[src]=0;
         return true;
     }
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        int check[v]={0};
        int visited[v]={0};
        int path[v]={0};
        for(int i=0;i<v;i++){
            if(visited[i]==0)
              dfscycle(path,visited,check,adj,i);
        }
        vector<int>ans;
        for(int i=0;i<v;i++)
          if(check[i])
            ans.push_back(i);
    return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends