pair<int,int> helper(string &s,int a){
     int n = s.length();
    int len = 0, sp = 0;
    for(int i=0;i<n;i++){
       int l = i+a, h = i;
        while(l-1>=0 && h+1<n && s[l-1]==s[h+1]){
            l--;
            h++;
        }
        if(len<(h-l+1)){
            len = (h - l + 1);
            sp = l;
        }
    }
    return {len,sp};
}

string longestPalinSubstring(string str)
{
   pair<int,int>mid,non_mid;
    mid=helper(str,0);
    non_mid=helper(str,1);
    string ans;
    if(mid.first>non_mid.first)
        ans=str.substr(mid.second,mid.first);
    else
        ans=str.substr(non_mid.second,non_mid.first);
    return ans;
}