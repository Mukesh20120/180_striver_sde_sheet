//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //store our answer in the vector
       vector<int>ans(V);
       for(int i=0;i<V;i++)
          ans[i]=INT_MAX;
          
          
        //making adj list 
        vector<pair<int,int>>Adj[V];
    for(int i=0;i<V;i++){
       for(int j=0;j<adj[i].size();j++){
           int v=adj[i][j][0];
           int w=adj[i][j][1];
           Adj[i].push_back({v,w});
           Adj[v].push_back({i,w});
       }
    }
    
    //min priority queu
   // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    set<pair<int,int>>pq;
    pq.insert({S,0});
    
    ans[S]=0;
    while(pq.size()){
       auto t=*(pq.begin());
       pq.erase(t);
       int node=t.first;
       int w=t.second;
        for(auto &it: Adj[node]){
            if(w+it.second<ans[it.first]){
                ans[it.first]=w+it.second;
                pq.insert({it.first,ans[it.first]});
            }
        }
        
    }
    return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends