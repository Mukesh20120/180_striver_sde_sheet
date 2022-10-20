// find the cycle in the graph question is based on topology sort but it
//boil down to find the cycle in the directed graph
//so we don't need to store the topo sort in the stack

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     bool dfstopo(vector<int>adj[],int src,stack<int>&st,int visit[],int path[]){
         visit[src]=1;
         path[src]=1;
         for(auto &it: adj[src]){
             if(visit[it]==0){
               if(dfstopo(adj,it,st,visit,path))
                   return true;
             }
             else if(path[it]==1)
                return true;
         }
         path[src]=0;
         st.push(src);
         return false;
     }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    stack<int>st;
	    vector<int>adj[N];
	    int path[N]={0};
	    int visited[N]={0};
	    for(auto &it: prerequisites){
	        adj[it.second].push_back(it.first);
	    }
	    
	   for(int i=0;i<N;i++)
	     if(visited[i]==0)
	           if(dfstopo(adj,i,st,visited,path))
	               return false;
	           
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends

//detecting cycle in directed graph
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     bool dfstopo(vector<int>adj[],int src,int visit[],int path[]){
         visit[src]=1;
         path[src]=1;
         for(auto &it: adj[src]){
             if(visit[it]==0){
               if(dfstopo(adj,it,visit,path))
                   return true;
             }
             else if(path[it]==1)
                return true;
         }
         path[src]=0;
         return false;
     }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N];
	    int path[N]={0};
	    int visited[N]={0};
	    for(auto &it: prerequisites){
	        adj[it.second].push_back(it.first);
	    }
	    
	   for(int i=0;i<N;i++)
	     if(visited[i]==0)
	           if(dfstopo(adj,i,visited,path))
	               return false;
	           
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
