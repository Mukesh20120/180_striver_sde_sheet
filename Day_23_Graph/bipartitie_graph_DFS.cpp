bool checkdfs(int color[],vector<int>adj[],int src,int c){
    color[src]=c;
    for(auto &it: adj[src]){
        if(color[it]==-1){
          if(!checkdfs(color,adj,it,!color[src]))
              return false;
        }
        else if(color[it]==c)
            return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
	vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int color[n];
    for(int i=0;i<n;i++)
        color[i]=-1;
    for(int i=0;i<n;i++){
        if(color[i]==-1 && !checkdfs(color,adj,i,0))
            return false;
    }
    return true;
}