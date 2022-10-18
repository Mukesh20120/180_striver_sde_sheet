struct Node{
    Node *hash[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++)
            hash[i]=NULL;
        flag=false;
    }
};
Node *root;

void insert(string s){
    Node *cur=root;
    for(char &c: s){
        int i=c-'a';
        if(cur->hash[i]==NULL)
            cur->hash[i]=new Node();
        cur=cur->hash[i];
    }
    cur->flag=true;
}
bool check(string s){
    Node *cur=root;
    for(char &c: s){
        int i=c-'a';
        if(cur->hash[i]==NULL)
            return false;
        cur=cur->hash[i];
    }
    return cur->flag;
}

int distinctSubstring(string &word) {
    //we use trie data struce to check if the word present
    //we check if it present we move ahead
    //and if not count insert
    root=new Node();
    int ans=0;
    int n=word.length();
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            string t=word.substr(i,j);
            if(!check(t)){
                ans++;
                insert(t);
            }
        }
    }
    return ans;
}
