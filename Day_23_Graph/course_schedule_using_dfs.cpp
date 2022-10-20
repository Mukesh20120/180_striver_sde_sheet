//question is based on topo sort but it mix with find cycle also
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  bool dfstopo(int visit[],vector<int>adj[],stack<int>&st,int src,int path[]){
      visit[src]=1;
      path[src]=1;
      for(auto &it: adj[src]){
          if(visit[it]==0){
              if(dfstopo(visit,adj,st,it,path))
                return true;;
          }
          else if(path[it]==1)
            return true;
      }
      st.push(src);
      path[src]=0;
      return false;
  }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
       //first we make adj vector
       vector<int>adj[n];
       for(auto &it: prerequisites){
           int u=it[0],v=it[1];
           adj[v].push_back(u);
       }
       stack<int>st;
       int path[n]={0};
       int visit[n]={0};
       for(int i=0;i<n;i++)
          if(visit[i]==0 && dfstopo(visit,adj,st,i,path))
               return {};
               
      vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.size()==n)return ans;
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends


//solving using BFS topo sort simple no need to check the cycle in this solution
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
       //first we make adj vector
       vector<int>adj[n];
       int inorder[n]={0};
       for(auto &it: prerequisites){
           int u=it[0],v=it[1];
           adj[v].push_back(u);
           inorder[u]++;
       }
       
       vector<int>ans;
       queue<int>q;
       
       for(int i=0;i<n;i++)
          if(inorder[i]==0)
            q.push(i);
            
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it: adj[node]){
                inorder[it]--;
                if(inorder[it]==0)
                   q.push(it);
            }
        }
        if(ans.size()==n)
           return ans;
         return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends