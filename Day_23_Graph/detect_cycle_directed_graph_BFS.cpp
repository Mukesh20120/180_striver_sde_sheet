#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
    //we generate topo sort if we able to build the array
    vector<int>adj[v+1];
    vector<int>inorder(v+1,0);
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        inorder[v]++;
    }
   queue<int>q;
    for(int i=1;i<v;i++)
        if(inorder[i]==0)
            q.push(i);
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto it: adj[node]){
            inorder[it]--;
            if(inorder[it]==0)
                q.push(it);
        }
    }
    if(cnt==v)return false;
    return true;
}