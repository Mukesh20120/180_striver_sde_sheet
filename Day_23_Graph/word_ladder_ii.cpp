//brute solution saving list in queue and 
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string bw, string ew, vector<string>& wl) {
         unordered_set<string>st(wl.begin(),wl.end());
         queue<vector<string>>q;
         q.push({bw});
         int level=0;
         vector<string>usedonlevel;
         vector<vector<string>>ans;
         while(!q.empty()){
             vector<string>vec=q.front();
             q.pop();
             if(vec.size()>level){
                 level++;
                 for(auto &it: usedonlevel)
                    st.erase(it);
                usedonlevel.clear();
             }
             string word=vec.back();
             if(word==ew){
                 if(ans.size()==0)
                     ans.push_back(vec);
                else if(ans[0].size()==vec.size())
                   ans.push_back(vec);
             }
             
             for(int i=0;i<word.length();i++){
                 char ori=word[i];
                 for(char c='a';c<='z';c++){
                     word[i]=c;
                     if(st.find(word)!=st.end()){
                         vec.push_back(word);
                         q.push(vec);
                         usedonlevel.push_back(word);
                         vec.pop_back();
                     }
                 }
                 word[i]=ori;
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends