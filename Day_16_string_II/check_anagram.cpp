bool areAnagram(string &str1, string &str2){
    int hash[26];
    if(str1.length()!=str2.length())
        return false;
    int n=str1.length();
    memset(hash,0,sizeof(hash));
    int cnt=0;
    for(int i=0;i<n;i++){
        int a=str1[i]-'a';
        hash[a]++;
        int b=str2[i]-'a';
        hash[b]--;
    }
    for(int i=0;i<26;i++){
        if(hash[i]!=0)
            return false;
    }
    return true;
}