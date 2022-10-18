
#include <bits/stdc++.h>
bool checkcolor(vector<int>&color,vector<int>adj[],int i){
    color[i]=0;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int src=q.front();
 
        q.pop();
        for(auto &it: adj[src]){
            if(color[it]==-1){
                color[it]=!color[src];
                q.push(it);
            }
            else if(color[it]==color[src])
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	//let first make a adj matric
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
    
    vector<int>color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1 && !checkcolor(color,adj,i))
            return false;
    }
    return true;
}