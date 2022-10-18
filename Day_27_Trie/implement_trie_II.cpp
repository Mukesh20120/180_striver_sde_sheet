struct Node{
    Node *hash[26];
    int cnt;
    int  end;
    Node(){
        for(int i=0;i<26;i++)
            hash[i]=NULL;
        cnt=0;
        end=0;
    }
};

Node *root;

class Trie{

    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
       Node *cur=root;
        for(char &c: word){
            int i=c-'a';
            if(cur->hash[i]==NULL)
                cur->hash[i]=new Node();
            cur=cur->hash[i];
            cur->cnt++;
        }
        cur->end++;
    }

    int countWordsEqualTo(string &word){
       Node *cur=root;
        for(char &c: word){
            int i=c-'a';
            if(cur->hash[i]==NULL)
               return 0;
            cur=cur->hash[i];
        }
       return cur->end; 
    }

    int countWordsStartingWith(string &word){
        Node *cur=root;
        for(char &c: word){
            int i=c-'a';
            if(cur->hash[i]==NULL)
               return 0;
            cur=cur->hash[i];
        }
       return cur->cnt; 
    }

    void erase(string &word){
        Node *cur=root;
        for(char &c: word){
            int i=c-'a';
            if(cur->hash[i]==NULL)
               return;
            cur=cur->hash[i];
            cur->cnt--;
        }
        cur->end--;
    }
};
