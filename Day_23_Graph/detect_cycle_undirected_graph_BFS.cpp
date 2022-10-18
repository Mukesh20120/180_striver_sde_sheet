    private:
     bool bfsCycle(int src,vector<bool>&visited,vector<int> adj[]){
         visited[src]=true;
         queue<pair<int,int>>q;
         q.push({src,-1});
         while(!q.empty()){
             int node=q.front().first;
             int parent=q.front().second;
             q.pop();
             for(auto adjacentNode: adj[node]){
                 if(!visited[adjacentNode]){
                     visited[adjacentNode]=true;
                     q.push({adjacentNode,node});
                 }
                 else if(adjacentNode !=parent)
                    return true;
             }
         }
         return false;
     }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        //so we get multiple source we have
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfsCycle(i,visited,adj))
                   return true;
            }
        }
        return false;
    }
};