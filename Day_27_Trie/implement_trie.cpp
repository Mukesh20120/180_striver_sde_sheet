/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
//node of trie data structure
struct Node{
    Node *hash[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++)
            hash[i]=NULL;
        flag=false;
    }
};
Node *root;//making global
class Trie {

public:

    /** Initialize your data structure here. */
    Trie() {
      root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur=root;
        for(char &c: word){
            int i=c-'a';
            if(cur->hash[i]==NULL)
                cur->hash[i]=new Node();
            cur=cur->hash[i];
        }
        cur->flag=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur=root;
        for(char &c: word){
            int i=c-'a';
            if(cur->hash[i]==NULL)
                return false;
            cur=cur->hash[i];
        }
        return cur->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur=root;
        for(char &c: prefix){
            int i=c-'a';
            if(cur->hash[i]==NULL)
                return false;
            cur=cur->hash[i];
        }
        return true;
    }
};