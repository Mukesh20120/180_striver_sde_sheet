#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   //make a adj list
    vector<int>adj[v];
     vector<int>inorder(v,0);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        inorder[v]++;
    }
    //now we have to make another list in which all the inorder came
   
    //now we have to find the those we have inorder 0 and push it into the queue
    queue<int>q;
    
    for(int i=0;i<v;i++)
        if(inorder[i]==0)
            q.push(i);
        
    vector<int>topo;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        topo.push_back(t);
        for(auto it: adj[t]){
            if(--inorder[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}