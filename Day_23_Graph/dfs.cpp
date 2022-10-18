void dfs(vector<int>&visit,int src,vector<int>adj[],vector<int>&temp){
   temp.push_back(src);
            visit[src]=1;
    for(auto it: adj[src]){
        if(visit[it]==0){
            dfs(visit,it,adj,temp);
        }
            
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    vector<int>visit(v,0);
    vector<int>adj[v];
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    vector<int>temp;
    for(int i=0;i<v;i++){
        if(visit[i]==0){
          vector<int>temp;
            dfs(visit,i,adj,temp);
            ans.push_back(temp);
        }     
    }
    return ans;
}