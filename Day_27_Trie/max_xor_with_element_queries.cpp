#include <bits/stdc++.h>
struct Node{
    Node *hash[2];
    Node(){
        hash[0]=hash[1]=0;
    }
};
Node *root;

void insert(int x){
    Node *cur=root;
    for(int i=31;i>=0;i--){
        int j=(x>>i)&1;
        if(cur->hash[j]==NULL)
            cur->hash[j]=new Node();
        cur=cur->hash[j];
    }
}
//the value gave max xor 
int check(int x){
    Node *cur=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        int j=(x>>i)&1;
        if(cur->hash[!j]==NULL){
            cur=cur->hash[j];
            ans=ans|(j<<i);
        }
        else{
            int t=!j;
            cur=cur->hash[t];
            ans=ans|(t<<i);
        }
    }
    return ans;
}
static bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	root=new Node();
    int q=queries.size();
    int n=arr.size();
   vector<int>ans(q,-1);
    //we need to sort the queries so we need index
    for(int i=0;i<q;i++)
        queries[i].push_back(i);
    //now sort the arr and queries
    sort(arr.begin(),arr.end());
    sort(queries.begin(),queries.end(),cmp);
    int j=0;
    for(int i=0;i<q;i++){
        while(j<n && arr[j]<=queries[i][1]){
            insert(arr[j]);
            j++;
        }
       if(j>0)
           ans[queries[i][2]]=(check(queries[i][0])^queries[i][0]);
    }
    return ans;
}




