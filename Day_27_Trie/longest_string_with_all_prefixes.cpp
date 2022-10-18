struct Node{
    Node *hash[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++)
            hash[i]=NULL;
        flag=false;
    }
};
static bool cmp(string &a,string &b){
    return a.length()<b.length();
}
void insert(string &s,Node *root){
    Node *cur=root;
    for(char &c: s){
        int i=c-'a';
        if(cur->hash[i]==NULL)
            cur->hash[i]=new Node();
        cur=cur->hash[i];
    }
    cur->flag=true;
}
bool check(string s,Node *root){
    Node *cur=root;
    for(char &c: s){
        int i=c-'a';
        if(cur->hash[i]==NULL)
            return false;
       cur=cur->hash[i];
    }
    return cur->flag;
}
string completeString(int n, vector<string> &a){
   //let sort the array from its string length
    sort(a.begin(),a.end(),cmp);
    //we make a data structure so that we can store all string
    Node *root=new Node();
    for(string &s: a)
        insert(s,root);
    
    string ans="None";
    bool flag;
    for(int i=a.size()-1;i>=0;i--){
        flag=true;
        for(int j=1;j<=a[i].length();j++){
            if(!check(a[i].substr(0,j),root)){
                flag=false;
                break;
            }   
        }
        if(flag){
            ans=a[i];
            break;
        }
    }
    return ans;
}