//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& fli, int src, int dst, int K)  {
       //make adj list
       vector<pair<int,int>>adj[n];
       for(int i=0;i<fli.size();i++){
           int u=fli[i][0];
           int v=fli[i][1];
           int c=fli[i][2];
           adj[u].push_back({v,c});
       }
       //make a distance array
       vector<int>price(n,1e9);
       //queue data structrue store   stops/node/cost
       queue<pair<int,pair<int,int>>>q;
       price[src]=0;
       q.push({0,{src,0}});
       while(!q.empty()){
           int stop=q.front().first;
           int node=q.front().second.first;
           int cost=q.front().second.second;
           q.pop();
           if(stop>K)
           continue;
           for(auto &it: adj[node]){
               if(price[it.first]>cost+it.second && stop<=K){
                   price[it.first]=cost+it.second;
                   q.push({stop+1,{it.first,price[it.first]}});
               }
           }
       }
       if(price[dst]==1e9)return -1;
       
       return price[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends