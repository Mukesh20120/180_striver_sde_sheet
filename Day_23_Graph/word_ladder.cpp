//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string sw, string tw, vector<string>& wl) {
       unordered_set<string>st(wl.begin(),wl.end());
       queue<pair<string,int>>q;
       q.push({sw,1});
       int ans=0;
       st.erase(sw);
       while(!q.empty()){
           string temp=q.front().first;
           int x=q.front().second;
           q.pop();
           if(temp==tw)
           return x;
           for(int i=0;i<temp.length();i++){
               char ori=temp[i];
               for(char c='a';c<='z';c++){
                   temp[i]=c;
                   if(st.find(temp)!=st.end()){
                       q.push({temp,x+1});
                       st.erase(temp);
                   }
               }
               temp[i]=ori;
           }
       }
       return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends