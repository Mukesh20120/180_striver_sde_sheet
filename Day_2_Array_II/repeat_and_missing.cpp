//brute force using hashing
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    //let use hashing
    int n=A.size();
    vector<int>hash(n+1,0);
    for(int it: A)
       hash[it]++;
    int a,b;
    for(int i=0;i<=n;i++){
        if(hash[i]>1)
          a=i;
        else if(hash[i]==0)
          b=i;
    }
    return {a,b};
}
