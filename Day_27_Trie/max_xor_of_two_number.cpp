struct Node{
    Node *hash[2];//store 0 and 1 reference
    Node(){
        hash[0]=hash[1]=NULL;
    }
};

Node *root; //global root variable

void insert(int a){
    //insert it bit wise from left to right
    Node *cur=root;
    for(int i=31;i>=0;i--){
        int j=1&(a>>i);
      if(cur->hash[j]==NULL)
           cur->hash[j]=new Node();
        cur=cur->hash[j];
    }
}

int check(int x){
    Node *cur=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        int j=1&(x>>i);
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

int maximumXor(vector<int> A)
{
    root=new Node();
    for(int &it: A)
        insert(it);
     int ans=0;
   
    for(int &it: A){
       int a=check(it);
        ans=max(ans,a^it);
    }
    return ans;
}