#define ll long long
ll p=31,mod=1e9+7;
ll poly_hash(string pat){
    ll res=1,ans=0;
    for(char &c: pat){
        ans+=(c-'A'+1)*res;
        res*=p;
        ans%=mod;
        res%=mod;
    }
    return ans;
}
ll pow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)
            ans*=a;
        b/=2;
        a*=a;
        ans%=mod;
        a%=mod;
    }
    return ans;
}
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int n=str.length();
    int m=pat.length();
    
    ll pat_hash=poly_hash(pat);
    ll str_hash=poly_hash(str.substr(0,m));
    vector<int>ans;
    if(pat_hash==str_hash)
        ans.push_back(0);
    for(int i=0;i+m<n;i++){
        str_hash=(str_hash-(str[i]-'A'+1)+mod)%mod;
        str_hash=str_hash*(pow(p,mod-2))%mod;
        str_hash=(str_hash+(str[i+m]-'A'+1)*pow(p,m-1))%mod;
        
        if(str_hash==pat_hash)
            ans.push_back(i+1);
    }
    return ans;
}
