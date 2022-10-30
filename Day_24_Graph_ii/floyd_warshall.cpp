//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	  //step 1 we change the -1 to 1e9
	  int n=matrix.size();
	  for(int i=0;i<n;i++){
	      for(int j=0;j<n;j++){
	          if(matrix[i][j]==-1)
	             matrix[i][j]=1e9;
	          if(i==j)
	            matrix[i][j]=0;
	      }
	  }
	  
	  //step2 we take every via
	  for(int k=0;k<n;k++){
	      for(int i=0;i<n;i++){
	          for(int j=0;j<n;j++){
	              matrix[i][j]=min(matrix[i][j],matrix[k][j]+matrix[i][k]);
	          }
	      }
	  }
	  
	  //step3 change every 1e9 to -1
	   for(int i=0;i<n;i++){
	      for(int j=0;j<n;j++){
	          if(matrix[i][j]==1e9)
	             matrix[i][j]=-1;
	      }
	  }
	  
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends